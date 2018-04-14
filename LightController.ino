#define F_CPU 8000000
#define   N   8
#include  <IRremote.h> 

int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results ir_results;
int feedback_pins[N] = {5, 6, 7, 8, 12, 11, 10, 9};
int output_pins[N] = {3, 2, A0, A1, A5, A4, A3, A2};

boolean lights_on[N];
boolean lights_in[N];
boolean saved_state[N];
boolean something_changed = true;

int delay_ms = 100;
int long_wait_time = 100;
int short_wait_time = 50;
int cycles_since_ir_input = 0;
long last_action = 0;
int lights_on_count = 0;

void update_lights_in() {
    for (int i=0; i<N; i++) {
        if (digitalRead(feedback_pins[i])) {
            lights_in[i] = true;
        } else {
            lights_in[i] = false;
            lights_on[i] = false;
        }
    }
}

void shift_forward(boolean next_light_state) {
    boolean temp = false;
    for (int i=0; i<N; i++) {
        if (lights_in[i]) {
            temp = lights_on[i];
            lights_on[i] = next_light_state;
            next_light_state = temp;
        } else {
            lights_on[i] = false;
        }
    }
}

void shift_backward() {
    boolean prev_light_state = false;
    boolean temp = false;
    for (int i=N-1; i>=0; i--) {
        if (lights_in[i]) {
            temp = lights_on[i];
            lights_on[i] = prev_light_state;
            prev_light_state = temp;
        } else {
            lights_on[i] = false;
        }
    }
}

void all_on() {
    for (int i=0; i<N; i++) {
        if (lights_in[i]) {
            lights_on[i] = true;
        }
    }
}

void all_off() {
    for (int i=0; i<N; i++) {
       lights_on[i] = false;
    }
}

void toggle_power() {
    if (lights_on_count == 0) {
        for (int i=0; i<N; i++) { 
            if (lights_in[i]) {
                lights_on[i] = saved_state[i];
            } else {
                lights_on[i] = false;
            }
        }
    } else {
        for (int i=0; i<N; i++) { 
            if (lights_in[i]) {
                saved_state[i] = lights_on[i];
            } else {
                saved_state[i] = false;
            }
            lights_on[i] = false;
        }
    }
}

void invert() {
    for (int i=0; i<N; i++) {
        if (lights_in[i]) {
            lights_on[i] = !lights_on[i];
        } else {
            lights_on[i] = false;
        }
    }
}

void random_sequence() {
    for (int i=0; i<N; i++) {
        lights_on[i] = false;
        if (lights_in[i]) {
            if (random(2) == 1){
                lights_on[i] = true;
            }
        }
    }
}

void enact() {
    int write_val = 0;
    something_changed = false;
    lights_on_count = 0;
    for (int i=0; i<N; i++) {
        write_val = 0;
        if (lights_on[i] && lights_in[i]) {
            write_val = 1;
            lights_on_count++;
        } else {
            lights_on[i] = false;
        }
        if (digitalRead(output_pins[i]) != write_val) {
            digitalWrite(output_pins[i], write_val);
            something_changed = true;
        }
    }
}

void represent_output(char string_representation[]) {
    for (int i=0; i<N; i++) {
        string_representation[i] = 'N';
        if (lights_in[i]) {
            string_representation[i] = '0';
            if (lights_on[i]) {
                string_representation[i] = '1';
            }
        }
    }
}

void setup() {
    for (int i=0; i<N; i++) {
        pinMode(feedback_pins[i], INPUT);
        pinMode(output_pins[i], OUTPUT);
        lights_on[i] = false;
        lights_in[i] = false;
    }
    irrecv.resume();
    irrecv.enableIRIn();
    // Serial.begin(115200);
    // Serial.flush();
    randomSeed(203);
}

void loop() {
    update_lights_in();
    if (irrecv.decode(&ir_results)) {
        long actionable = 0;  
        actionable = ir_results.value;
        // Serial.println(actionable, HEX);
        // Serial.flush();
        if (actionable == 0xFFFFFFFF) {
            actionable = last_action;    
        }
        switch (actionable) {
            case 0x77E150EF:  // plus (Apple)
            case 0x10EFA05F:  // plus (sparkfun [^])
                shift_forward(true);
                break;
            case 0x77E160EF:  // forward (Apple)
            case 0x10EF807F:  // forward (sparkfun [>])
                shift_forward(false);
                break;
            case 0x77E130EF:  // minus (Apple)
            case 0x10EF00FF:  // minus (sparkfun [v])
                shift_backward();
                break;
            case 0x77E190EF:  // backward (Apple)
            case 0x10EF10EF:  // backward (sparkfun [<])
                shift_backward();
                break;
            case 0x77E1A0EF:  // bright (Apple [playpause])
            case 0x10EFF807:  // bright (sparkfun [A])
                all_on();
                break;
            case 0x77E1C0EF:  // dark (Apple [menu])
            case 0x10EF20DF:  // dark (sparkfun [O])
                all_off();
                break;
            case 0x10EFD827:  // power (sparkfun)
                toggle_power();
                break;
            case 0x10EF58A7:  // invert (sparkfun [C])
                invert();
                break;
            case 0x10EF7887:  // random (sparkfun [B]) 
                random_sequence();
                break;
            default:
                break;
        }
        last_action = actionable;
        irrecv.resume();
        delay_ms = short_wait_time;
        cycles_since_ir_input = 0;
    } else {
        if (delay_ms != long_wait_time) {
            if (cycles_since_ir_input > 50) {
                delay_ms = long_wait_time;
                last_action = 0;
            }
            cycles_since_ir_input++;
        }
    }
    enact();
    // Serial.println("Working");
    delay(delay_ms);
}
# Fairy Light Controller

Initially when we bought [fairy lights](https://www.amazon.com/gp/product/B00I7M7C40/) (sorry for the amazon link, I hope it stays valid for a while) they came with crappy wall warts which had to be plugged and unplugged daily; these wall warts were of such poor quality that the barrel plug which recieved the light strand would inevitably break. 
Totally unacceptable.
The goal of this project is to provide an easy interface for controlling and powering many strands of LED fairy lights.

## Features

* 40 Watt Power supply,
* ATMega328P,
* IR Reciever and [Remote Control](https://www.sparkfun.com/products/11759) [also works with a little white apple remote if you have one laying around],
* Barrel Plugs for 8 light strands,
* Laser cut acrylic case.

## What's included

* Code for the ATMega328P,
* KiCAD files for the control board. [OSHPark project for this board](https://oshpark.com/shared_projects/VDE5yBSG),
* Bill of Materials (here in this README),
* SVG files for cutting the case parts.

## Bill of Materials

Here is what you'll need to order to build this thing. I generally order the parts from a few different suppliers due to availability and price so bear with me. 

| Part # | Qty | Reference | Description | MFR # (link) | Supplier | Notes |
|--------|-----|-----------|-------------|--------------|----------|-------|
|1|1|C1|Capacitor 100uF (SMD-1206)|[GRM31CD80J107ME39L](https://www.mouser.com/ProductDetail/81-GRM31CD80J107ME9L)|Mouser||
|2|1|C2|Capacitor 10uF (SMD-0805)|[GRM21BC81C106ME15L](https://www.mouser.com/ProductDetail/Murata-Electronics/GRM21BC81C106ME15L?qs=sGAEpiMZZMs0AnBnWHyRQKFZIQ7b73cd5p1OjeXSJs7IZ5GPsfC2iQ%3d%3d)|Mouser||
|3|1|C3|Capacitor 100nF (SMD-0805)|[100nF 50V 0805](https://www.taydaelectronics.com/100nf-50v-smd-ceramic-chip-capacitor.html)|Tayda|If you order 100 of these they will last you a long time.|
|4|1|C4|Capacitor 1uF (Radial D5L11)|[105CKR100M](https://www.mouser.com/ProductDetail/Illinois-Capacitor-CDE/105CKR100M?qs=sGAEpiMZZMtZ1n0r9vR22fPWwtj8kO8aXBFG7%252b0kMMHBNQpcXdefQA%3d%3d)|Mouser||
|5|8|CON1--CON8|Barrel Jack|[KLDX-SMT-0202-AP](https://www.mouser.com/ProductDetail/806-KLDX-SMT0202AP)|Mouser|These are sized to fit the fairy lights linked below.|
|6|1|IC1|Microcontroller|[ATMEGA328P-P](https://www.taydaelectronics.com/atmega328p-pu-atmega328-microcontroller-ic.html)|Tayda|An Arduino chip without the Arduino board. You'll have to have a means to program it (an Arduino board will work nicely for that)|
|7|1|P1|Connector 4POS|[B4PS-VH(LF) (SN)](https://www.digikey.com/product-detail/en/jst-sales-america-inc/B4PS-VH(LF)(SN)/455-1650-ND/926557)|Digi-key|Receive the power onto the board.|
|8|8|Q1--Q8|NPN Darlinton Pair (SOT-223)|[FZT600TA](https://www.mouser.com/ProductDetail/522-FZT600TA)|Mouser||
|9|8|R1--R8|Resistor 0.27 Ohm (Thru-hole)|[MOSX1CT52RR27J](https://www.mouser.com/ProductDetail/660-MOSX1CT52RR27J)|Mouser||
|10|1|R9|Resistor 0 Ohm (SMD-0805)|[0 Ohm 1/8W 1% 0805](https://www.taydaelectronics.com/50-x-smd-chip-resistors-0-ohm-1-8w-1-0805.html)|Tayda|If you order 100 of these they will last you a long time.|
|11|1|R10|Resistor 100 Ohm (SMD-0805)|[100 Ohm 1/8W 1% 0805](https://www.taydaelectronics.com/50-x-smd-chip-resistors-100-ohm-1-8w-1-0805.html)|Tayda|If you order 100 of these they will last you a long time.|
|12|1|R11|Resistor 10k Ohm (SMD-0805)|[10K Ohm 1/8W 1% 0805](https://www.taydaelectronics.com/50-x-smd-chip-resistors-10k-ohm-1-8w-1-0805.html)|Tayda|If you order 100 of these they will last you a long time.|
|13|2|RR1--RR2|Resistor Array (Bussed) 10k Ohm (SIP-9)|[4609X-101-103LF](https://www.mouser.com/ProductDetail/652-4609X-1LF-10K)|Mouser|8 Resistors| 9 Pins|
|14|1|U1|IR Reciever (38 khz)|[TSOP34438](https://www.mouser.com/ProductDetail/522-FZT600TA)|Mouser||
|15|1|X1|Crystal Oscillator (with Caps)|[CSTLS8M00G53-A0](https://www.mouser.com/ProductDetail/81-CSTLS8M00G53-A0)|Mouser||
|16|1|NA|Power Supply 40W|[EPS-45-5-C](https://www.mouser.com/ProductDetail/709-EPS45-5-C)|Mouser||
|17|10|NA|Connector Terminal Crimp-ons|[SVH-41T-P1.1](https://www.digikey.com/product-detail/en/jst-sales-america-inc/SVH-41T-P1.1/455-1319-1-ND/608888)|Digi-key|Those little silver things you have to smash onto your wires.|
|18|2|NA|Connector Housing 4POS|[VHR-4N](https://www.digikey.com/product-detail/en/jst-sales-america-inc/VHR-4N/455-1185-ND/608626)|Digi-key|To get power from the power supply to the board|
|19|1|NA|Connector Housing 3POS|[VHR-3N](https://www.digikey.com/product-detail/en/jst-sales-america-inc/VHR-3N/455-1184-ND/608625)|Digi-key|To get power from the wall to the power supply|
|20|1|NA|Remote Control|[COM-11759](https://www.sparkfun.com/products/11759)|Sparkfun|The software also supports the little white Apple remote control| but the sparkfun one allows more features.|
|21|1|NA|Power Cord||stayonline.com|The power supply insists on being grounded, and I am happy to oblige it. You can use an old PC power cable with one end cut off (choose wisely), or you can order to length.|
|22|8|NA|Fairy Lights|[B00I7M7C40](https://www.amazon.com/gp/product/B00I7M7C40/)|Amazon|It is pretty vital to get the ones with the barrel power connector that matches the barrel jacks (Item 5). Minimum 1, maximum 8|
|23|1|NA|Battery for Remote Control|CR2025|Lots of places|You figure it out|
|24|1|NA|28 pin DIP IC Socket|[28 pin DIP IC Socket](https://www.taydaelectronics.com/28-pin-dip-ic-socket-adaptor-solder-type.html)|Tayda|This is what you'll actually solder to the board. Cram the ATMega328 into this.

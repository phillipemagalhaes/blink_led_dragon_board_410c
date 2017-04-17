# blink_led_dragon_board_410

This a program in C to make a LED blink using the GPIO 36 on a dragon board 410c.
Its used a circuit with a transistor as a switch to supply power enough to make 
the LED shine fully bright. 
The circuit schmatic can also be checked on the file circuit.

In order to run the program follow the steps :

Compile the source code (blink_led.c) 
gcc blink_led.c -o blink_led

Run the binary file as a superuser :

sudo ./blink_led

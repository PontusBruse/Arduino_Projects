This is a program that is implemented on an Arduino R3 Uno and it tests the watchdog.

If a button is pressed a counter will increase and print the current value of the counter.

If the button isn't pressed within 8 seconds the watchdog will reset the program and the counter will be set to zero again.
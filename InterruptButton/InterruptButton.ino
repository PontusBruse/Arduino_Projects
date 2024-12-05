#include <avr/wdt.h>
int buttonCount = 0 ;
volatile bool state = false;

void setup() {
  // Disable and then enable the watchdog with a 8 second timer.
  wdt_disable();
  delay(3000);
  wdt_enable(WDTO_8S);

  Serial.begin(9600); // Baudrate
  pinMode(2, INPUT_PULLUP); // Sets pin 2 to a built in pull-up-resistor
  attachInterrupt(digitalPinToInterrupt(2), ISR_button, FALLING); // Activate an intrerupt when pin 2 is faling(going from HIGH to LOW)
}

void loop() {
  //If button is pressed, increase buttonCount and print it.
  if (state) {
    buttonCount++;
    Serial.println(buttonCount);
    state = false;
  }
  delay(100);
  
}

//Changing the state and reset the watchdog
void ISR_button(){
  state = !state;
  wdt_reset(); 
}

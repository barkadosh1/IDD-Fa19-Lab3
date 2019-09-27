// all necessary include/define statements
#include <LiquidCrystal.h>
#include <EEPROM.h>
#define COMMON_ANODE

// EEPROM Constants
const int numStates1 = 2;
const int numStates2 = 3;
const int sensorMin = 0;
const int sensorMax = 1024;
const int EEPROMSIZE= 1024;
int state1, state2, lastState = -1;
int iteration2 = 0;
long timer_begin = -1.00;
long timer_end = 0.00;
long get_timer_begin = 0.0;
long get_timer_end = 0.0;
int timer_snoozed_1 = 0;

// lcd values
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// LED pin values
int redPin = 10;
int greenPin = 9;
int bluePin = 8; 

// Analog Pins
int photocell = 5;
int fsr = 1;

// Setup of LED, LCD, and Serial
void setup(void) {
  // set up LED pins as output pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

  // set initial LED to have no light/color
  setColor(0, 0, 0);
  
  Serial.begin(9600);

  // set up LCD and print start-up messages to LCD
  lcd.begin(16, 2);
  delay(1200);
}

void loop() {
  // FSR and Photo sensors values are read in to determine appropriate states 
  state1 = map(analogRead(photocell), sensorMin, sensorMax, 0, numStates1);
  state2 = map(analogRead(fsr), sensorMin, sensorMax, 0, numStates2);

  // If not enough sun has appeared yet, state 0 runs, simply telling the user to have sweet dreams
  switch (state1) {
  case 0:    
    lcd.clear();
    delay(100);
    lcd.setCursor(0,0);
    lcd.print("Sweet Dreams!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("zzzzzzzzz");
    lcd.setCursor(5,1);
    lcd.print("zzzzzzzzz");
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(150);
    }
    lcd.clear();
    break;
  // once enough sun appears, state 1 is run. Within state 1, there are 3 sub states for the FSR force. 
  // the first state is when the user still hasn't pressed the button. This is where I first start 
  // recording the timer. The second state is if the user is pressing the button but not hard enough. 
  // The third state is if the user is pressing the button hard enough and a 10 second timer will count down
  case 1:
    switch (state2) {
    case 0:
      timer();    
      doState0();
      break;
    case 1:    
      doState1();
      break;
    case 2:    
      doState2();
      break;
    } 
    lastState = state2;
    break;
  } 
}

// takes the RGB colors and lights up the LED
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

// Clever function I wrote so that the timer starts reading right around when the alarm actually starts 
// (when the red lights start flashing). The beginning time is placed in the EEPROM to be retrieved later
void timer() 
{
  if (timer_begin == -1.0) 
  {
    timer_begin = 0.0;
  }
  else if (timer_begin == 0.0) 
  {
    timer_begin = millis();
    EEPROM.put(0, timer_begin);
  }
}

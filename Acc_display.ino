// all necessary include statements
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

#define COMMON_ANODE

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

// lcd values
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// LED pin values
int redPin = 10;
int greenPin = 9;
int bluePin = 8; 

// Acceleration --> color variables
double acc_x;
double acc_y;
double acc_z;
double sum_xyz;
int x_red;
int y_green;
int z_blue;


void setup(void) {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif

  // set up LED pins as output pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 

  // set initial LED to have no light/color
  setColor(0, 0, 0);
  
  Serial.begin(9600);

  // set up LCD and print start-up messages to LCD
  lcd.begin(16, 2);
  lcd.print("LIS3DH test!");
  delay(1200);
  lcd.clear();
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    lcd.print("Couldnt start");
    while (1);
  }

  lcd.print("LIS3DH found!");
  delay(1200);
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  lcd.clear();
  lcd.print("Range = "); lcd.print(2 << lis.getRange());  
  lcd.print("G");
  delay(1300);
}

void loop() {
  lcd.clear();
  
  lis.read();      // get X Y and Z data at once

  /* normalized sensor events*/ 
  sensors_event_t event; 
  lis.getEvent(&event);
  
  /* Display the results on the LCD (acceleration is measured in m/s^2) */
  lcd.print("X:"); lcd.print(event.acceleration.x); lcd.print("  ");
  lcd.print("Y:"); lcd.print(event.acceleration.y); 
  lcd.setCursor(1,1);
  lcd.print("Z:"); lcd.print(event.acceleration.z); 
  lcd.print(" m/s^2 ");

  // absolute value of the x, y, and z accelerations. For z, 9.8 is subtracted out
  // so that the change from starting acceleration is displayed
  acc_x = abs(event.acceleration.x);
  acc_y = abs(event.acceleration.y);
  acc_z = abs(event.acceleration.z - 9.8);

  // sum the acceleration values
  sum_xyz = acc_x + acc_y + acc_z;

  // convert each acceleration (x, y, or z) and convert it to a value between 0 and 255
  // based on  its proportion relative to the sum of all of the accelerations
  x_red = (int) acc_x/sum_xyz*255.0;
  y_green = (int) acc_y/sum_xyz*255.0;
  z_blue = (int) acc_z/sum_xyz*255.0;

  // set the LED with the values for red, green, and blue converted from the x, y, and z
  // accelerations above
  setColor(x_red, y_green, z_blue);  // red
  delay(250); 
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

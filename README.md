# Data Logger (and using cool sensors!)

*A lab report by Bar Kadosh.*

## In The Report

Include your responses to the bold questions on your own fork of this lab report template. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 Connected Potentiiometer to A0 --> when potentiometer is turned all the way to one end value is 0, all the way to other end value is 1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**
2^10

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**
- made use of 100 ohm resistors -- 2 in parallel created a 50. Connect to power and 3 digital pins, remove cmommented analog line of code, run code.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

Using 22k ohm instead

**a. What voltage values do you see from your force sensor?**
Was able to get it as high as 1010 and as low as 30 -- prob goes until 1023

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**
Look up -- seems linear but hard to tell

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**


## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

# Data Logger (and using cool sensors!)

*A lab report by Bar Kadosh.*

## In The Report

Include your responses to the bold questions on your own fork of this lab report template. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 
After connecting my potentiometer to A0 and uploading the code, I began seeing values appearing on the serial monitor. When the potentiometer was turned all the way so that resistance was maximized, the A0 value being printed was 0. When the potentiometer was turned all the way to the other end so that resistance was minimized, the A0 value being printed was 1023. Therefore, the range of of the analog values was 0-1023 (1024 possible values).

[Analog Values on Serial Monitor](https://youtu.be/ujy_T5v5900) -- As can be seen in the video, the analog values being printed to the serial monitor range from 0 to 1023 as I turn the potentiometer from end to end. 

[Analog Values on Plotter](https://youtu.be/c9H6gWHCYMs) -- Similarly, as can be seen in this video, the analog values being printed on the plotter range from 0 to 1023 as I turn the potentiometer. 

**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

The analog to digital coverter (ADC) on the arduino allows for 1024 discrete analog values to be measured/printed, which is equivalent to 2^10 possible discrete analog values. Therefore, we can say that the ADC is a **10-bit ADC. **

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**
- made use of 100 ohm resistors -- 2 in parallel created a 50. Connect to power and 3 digital pins, remove cmommented analog line of code, run code.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

Using 22k ohm instead

**a. What voltage values do you see from your force sensor?**
Was able to get it as high as 1010 and as low as 30 -- prob goes until 1023

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**
Look up -- seems linear but hard to tell ---nvm, seems harder to raise as get higher

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**
LEDbrightness = map(fsrReading, 0, 1023, 2, 255);

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**
photo -- 22k: low as 10, high as 1014
softpot -- 10 k

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**


## Optional. Graphic Display

modified code to print A0 value
code
video

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**
- Yes, the states get performed in order, 0 then 1 then 2, so if you want your actions to follow a similar ordering, it matters where you assign them 

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

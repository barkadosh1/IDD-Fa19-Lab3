# Data Logger (and using cool sensors!)

*A lab report by Bar Kadosh.*

## In The Report

Include your responses to the bold questions on your own fork of this lab report template. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**
 
After connecting my potentiometer to A0 and uploading the code, I began seeing values appearing on the serial monitor. When the potentiometer was turned all the way so that resistance was maximized, the A0 value being printed was 0. When the potentiometer was turned all the way to the other end so that resistance was minimized, the A0 value being printed was 1023. Therefore, the range of of the analog values was 0-1023 (1024 possible values).

[Analog Values on Serial Monitor](https://youtu.be/ujy_T5v5900) -- As can be seen in this video, the analog values being printed to the serial monitor range from 0 to 1023 as I turn the potentiometer from end to end. 

[Analog Values on Plotter](https://youtu.be/c9H6gWHCYMs) -- Similarly, as can be seen in this video, the analog values being printed on the plotter range from 0 to 1023 as I turn the potentiometer. 

**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

The analog to digital coverter (ADC) on the arduino allows for 1024 discrete analog values to be measured/printed, which is equivalent to 2^10 possible discrete analog values. Therefore, we can say that the ADC is a **10-bit ADC.**

## Part B. RGB LED 

**How might you use this with only the parts in your kit? Show us your solution.**

One way we might make use of RGB LEDs is with Christmas lights that alternate colors — we can have all lights start as Green then shift to Red then shift to Blue and continue shifting in a fun and colorful way. Another potential application is if we wanted to mimic a traffic light with one LED for start-stop events. For example if we wanted to run a race, we could have the light start on red, shift to yellow to have us get set, and then start running as soon as it turns green. A last potential example is if we wanted to set up a trivia machine. We could have four buttons, each corresponding to an answer (one of which will be correct). If the correct answer is pressed, the LED turns green, and if the incorrect answer is pressed, the LED turns red.

During lab, I set up the RGB LED so that the color would alternate between six colors. As a remark about my setup — I made use of only 100 ohm resistors, so in order to account for the 150 ohm case with the Red segment of the RGB LED, I used a 100 ohm resistor in series with two 100 ohm resistors in parallel (equivalent to 150 ohms). The video of my RGB working is below.

[RGB LED Lights!](https://youtu.be/fB4QqWRvrmc)

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

With my force sensor, I am able to get values as low as 30 when I am barely pressing (the value starts at 0 if I am not pressing) and values as high as 1010 when I press as hard as I can. However, I was using a 22k Ohm resistor, so maybe using a 10k Ohm resistor would have allowed me to be able to produce the full range of values (0-102), though the range I was able to see with my setup was quite good/encompassing. 

[Voltage Readings With FSR](https://youtu.be/DdxIlCk6ZEA)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

For the most part, the simple description for the relationship I saw is linear. In general, when I pressed harder, the the voltage seemed to increase in a somewhat linear fashion. However, since I was only able to start at a voltage value of 30 and it only jumped up to that value once I applied a certain amount of force (this amount was quite low, but I did notice that if i pressed lightly enough, the voltage was 0), I think of the beginning of the relationship as a step function. Towards the higher values, I also noticed that I had press much harder to get the voltage readings to continue rising -- therefore, I like to think of the tail end of the relationship as logarithimic. Everything in between was fairly linear. A photo of the relationship between voltage and force in my setup is below.

<img src="https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/Screen%20Shot%202019-09-26%20at%204.12.58%20PM.png">

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Yes! A simple function we can use is the map() function. With the following line, "LEDbrightness = map(fsrReading, 0, 1023, 0, 255);", we can take "fsrReading" value (which is the FSR analog reading between 0 and 1023) and map it to an LED value between 0 and 255.

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
- clear read write --> tied to voltage, if we change it around order doesnt make sense, doesnt make sense to write when voltage is 0 

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

because the switchstate loop will call it through its own loop each time, otherwise, when going into a state we will end up in infinite loop until state change

**c. How many byte-sized data samples can you store on the Atmega328?**

1024

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

map from 10 bit to 8 bit -- of course you are losing some level of preciseness here 
from i2c, similarly would map. Typically it is 8 bit so no change, but otherwise we would map it with the bit value it might be. If dont know what bit value it is, can do a calculation where you find proportion, etc. 

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

ANSWER LATER

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

EXPLAIN CODE, WHAT IS HAPPENING 

CODE HERE

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

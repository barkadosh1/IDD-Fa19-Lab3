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

With my force sensor, I am able to get values as low as 30 when I am barely pressing (the value starts at 0 if I am not pressing) and values as high as 1010 when I press as hard as I can. However, I was using a 22k Ohm resistor, so maybe using a 10k Ohm resistor would have allowed me to produce the full range of values (0-1023), though the range I was able to see with my setup was quite good/encompassing. 

[Voltage Readings With FSR](https://youtu.be/DdxIlCk6ZEA)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

For the most part, the simple description for the relationship I saw is linear. In general, when I pressed harder, the voltage seemed to increase in a somewhat linear fashion. However, since I was only able to start at a voltage value of 30 and it only jumped up to that value once I applied a certain amount of force (this amount was quite low, but I did notice that if I pressed lightly enough, the voltage was still 0), I think of the beginning of the relationship as a step function. Towards the higher values, I also noticed that I had to press much harder to get the voltage readings to continue rising -- therefore, I like to think of the tail end of the relationship as logarithmic. Everything in between was fairly linear. A photo of the relationship between voltage and force in my setup is below.

<img src="https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/Screen%20Shot%202019-09-26%20at%204.12.58%20PM.png">

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Yes! A simple function we can use is the map() function. With the following line, "LEDbrightness = map(fsrReading, 0, 1023, 0, 255);", we can take "fsrReading" (which is the FSR analog reading between 0 and 1023) and map it to an LED value between 0 and 255.

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

For the photo cell, I used a resistance of 22k Ohms. With this resistance, I was able to output a voltage reading as low as 4 and as high as 1012, which is a very reasonable range of voltages. When the room was normally lit, it was ouputting a value of around 600. When I covered the photo cell with a wallet, the voltage output was 4 and when I placed a flashlight over it, the output voltage was 1012.

[Photo Sensor](https://youtu.be/s-2jSnQv7vY)

For the softpot, I used a 10k Ohm resistor. I was able to output the full range of voltages from 0 to 1023 as I slid my finger accross the softpot. As I moved accross the softpot, the resistance decreased and the voltage increased. 

[Softpot](https://youtu.be/YyoJhIp8nHc)

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

Unlike with the FSR, the relationships appear to be more stricly linear in these cases (most values are reachable and it doesn't seem like extra light or force is needed towards the higher voltages). As the photo sensor receives more light, it seems to increase linearly; similarly, as I moved my finger accross the softpot, the voltage values seemed to increase linearly with regards to how much I had moved my finger along the softpot. 

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

To begin with, I used the accelerometer code template. I then added in my LCD and my RGB LED. To set up, I set the RGB LED to have all values 0 (no light) and printed a couple of start-up messages on the LCD screen. Within the loop, I used the existing accelerometer code to capture and print the absolute values of the acceleration values (on the LCD screen). I chose to subtract 9.8 from the z acceleration to normalize its starting acceleration to 0 so that the accelerometer would capture changes from the initial acceleration. To convert these acceleration values to RGB values I did the following: I made the red value the proportion of x acceleration divided by the sum of x, y, and z accelerations and multiplied the value by 255. I did the same for the green and blue values, only I replaced the x acceleration in the numerator with y and z accelerations for green and blue, respectively. Finally, I flashed the LED with the colors based on these acceleration values. 

As can be seen in the video, when I lift my device up and down in the z direction, it lights up blue. When I move it from side to side in the y direction, it lights up green, and when I move it forward and backward in the x direction, it lights up red. 

[Accelerometer LED Display Code](https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/Acc_display.ino)

[Accelerometer LED Display Video](https://youtu.be/mwniKxg9oms)

## Optional. Graphic Display

For this part, I simply used the display to print the analog value to the display screen using "analogRead(A0)" and "display.print()" and "display.display()."

**Take a picture of your screen working insert it here!**

[Modified Graphic Display Code](https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/ssd1306_modified.ino)

[Modified Graphic Display Video](https://youtu.be/Z1XSXNLJ-3o)

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

Yes. The states are determined by the voltage reading from the specified analog. In this case, the first 1/3 voltages are classified as case 0, the second 1/3 of voltages as case 1, and the last 1/3 of voltages as case 2. Therefore, as we increase the voltage all the way up and then decrease it all the way down, we end up with the following sequence: clear --> read --> write --> read --> clear. This order seems to make sense as ultimately, we write the values to the EEPROM, read them, and then clear them. If we assign clear, read, and write to different states, we might end up with the following scenario when we turn the potentiometer all the way up and then back down: write --> clear --> read --> clear --> write. This case is clearly problematic because after we write our values, we clear them before we ever get to read them. Therefore, to achieve the ordering and output we are hoping for, it is very important that we assign the write actions to the write states given the current ordering of our states as it ties to the voltage output. 

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

Our switchstate loop will be the actual loop and will be checking which state we are in each each time through the loop. Therefore, through each loop, the doState() function will be called for the current state. Since the switchstate is already looping, it would be redundant to loop within the state as well; rather, we would like to just measure the analog reading for the one state and then exit the function so so that the main switchstate loop can run again and determine the next loop. Therefore, the state0, state1, and state2 functions will have their code in the setup as we only want them to run once for a given switchstateloop so that we can understand the voltage reading at that specific point in time.

**c. How many byte-sized data samples can you store on the Atmega328?**

We can store 1024 byte-sized data samples on the Atmega328. As we will see in part e, we can therefore store 1024 8-bit voltage readings, for example. 

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

From the arduino analog pins, we know we are going from 10 bits to one byte (8-bits), meaning we need to map from values 0-1023 to 0-255. Of course, we are losing some of the exactness in our values here, but it is a fine solution for now. To do this, we will cotinue to use the map function we have been using to convert 10-bit to 8-bit values. 

From an I2C device, the answer is more dependent on how many bits it is on that device. If the device is just 8 bits, then no change is needed. However, if it is another value of bits, and we know that value, we can use the map function again to map from the value of bits on the I2C device to 8 bits. 

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

Using the put function, we can store these values in a given memory address. However, if they are bigger than 1 byte, we will have to split them accross memory addresses. For example, for type float (4 bytes), we will have to store the value accross 4 memory addresses, as each house 1 byte. We will have to keep track in some way of where each part is stored and in what order so that we can reconstruct the value when we pull the portions back out of their memory addresses. 

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

For my setup, I had both a potentiometer and FSR set up. I was using the potentiometer to read in and determine what state to follow and used the FSR to have its values measured in the write state. For the most part then, I only really changed code in the write state (except for changing code in SwitchState2 to add in the potentiometer and FSR). Within my write code, I am reading in the analog value every time the write state is called (through the SwitchState loop) and map it from the 0-1023 value range to the 0-255 value range. I start by writing this value to the 0th memory address and increment the memory dress with each call to the write state. This writes a series of analog voltage values to the memory address and they are then printed during the read state. Once I enter the clear state, these values are removed and the memory addresses are filled with 0's. As I turn my potentiometer, it goes from clear --> read -- write. As I hold the FSR in the write state, it records analog voltage values. When I turn back into the read state, those values are printed and are then cleared when I return to the clear state.

[SwitchState2 Code](https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/SwitchState2.ino)

[State0 Code](https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/State0.ino)

[State1 Code](https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/State1.ino)

[State2 Code](https://github.com/barkadosh1/IDD-Fa19-Lab3/blob/master/State2.ino)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

// This borrows code from Examples->EEPROM->eeprom_write

// Resets timer to start at 10 if the user lets go of the button 
void state2Setup() {
  Serial.println("Writing to EEPROM");
  iteration2 = 0;
}

// After the user successfully holds the button for 10 second, the timer ends. The start and end times of snooze are pulled
// from the EEPROM and the toal snooze time is printed to the LCD
void state2End() {
  timer_end = millis();
  
  EEPROM.put(10, timer_end);

  EEPROM.get(0, get_timer_begin);
  EEPROM.get(10, get_timer_end);
  
  timer_snoozed_1 = (int) ((get_timer_end - get_timer_begin)/ 1000.0);

  lcd.setCursor(0,0);
  lcd.print("You Snoozed For:");
  lcd.setCursor(0,1);
  lcd.print(timer_snoozed_1);
  lcd.print(" Seconds");
  delay(1000);
  exit(0);
}

// While the user is pressing the button, the LCD tells them how many more seconds they must hold the button for
void state2Loop() {    
  delay(300);

  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Hold for "); 
  lcd.print(10 - iteration2);
  lcd.setCursor(0,1);
  lcd.print("More Seconds!");   
  setColor(0, 255, 0);  
  delay(300);
  setColor(0, 0, 0);  
  lcd.clear();
  delay(400);

  // Jumps to the end state function if the timer hits 0
  if (iteration2 == 10) {
    state2End();  
  }

  iteration2 += 1;
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
  
}

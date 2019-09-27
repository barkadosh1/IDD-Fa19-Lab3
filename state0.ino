// This borrows code from Examples->EEPROM->eeprom_clear

void state0Setup() {
}

// Once enough sun is present, this code tells the user they must press the button to turn off snooze
void state0Loop() { 
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Hold Button To"); 
  lcd.setCursor(0,1);
  lcd.print("Turn Off Snooze"); 
  setColor(255, 0, 0);  // red
  delay(300);
  setColor(0, 0, 0);  // red
  lcd.clear();
  delay(300);
}

void doState0() {
  if (lastState != 0) { state0Setup(); }
  state0Loop();
}

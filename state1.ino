// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
}

// If the user is holding the button but not hard enough, this piece of code tells them to push harder
void state1Loop() {
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Press Harder!"); 
  setColor(255, 125, 0);  // red
  delay(300);
  setColor(0, 0, 0);  // red
  lcd.clear();
  delay(300);
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}

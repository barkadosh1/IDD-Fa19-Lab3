// This borrows code from Examples->EEPROM->eeprom_read

byte value;

void state1Setup() {
  Serial.println("Reading from EEPROM");

  for (int i = 0; i < EEPROMSIZE; i++) {
    value = EEPROM.read(i);
    Serial.print(value);
    Serial.print(" ");
  }
  Serial.println();

  Serial.println("Done reading from EEPROM");
}

void state1Loop() {
}

void doState1() {
  if (lastState != 1) { state1Setup(); }
  state1Loop();
}

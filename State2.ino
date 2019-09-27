// This borrows code from Examples->EEPROM->eeprom_write

void state2Setup() {
  //digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");
}

void state2Loop() {  
  int value = map(analogRead(sensorPin), 0, 1023, 0, 255);

  EEPROM.write(iteration, value);
  iteration += 1; 
  delay(300);
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
  
}

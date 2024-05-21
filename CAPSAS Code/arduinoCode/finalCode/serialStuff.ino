void recvWithEndMarker() {
  if (Serial.available() >= 2) { // Check if at least 2 bytes are available
    byte1 = Serial.read(); // Read the first byte
    byte2 = Serial.read(); // Read the second byte
    /*
    Serial.print("Received bytes: ");
    Serial.print(byte1);
    Serial.print(", ");
    Serial.println(byte2);
    */
    newData = true;
  }
}

unsigned int showNewNumber() {
    if (newData == true) {
      newData = false;
      unsigned int i = (byte1 << 8) | byte2;
      //Serial.println(i);
      return i;
    } else {
      return 65535;
    }
}

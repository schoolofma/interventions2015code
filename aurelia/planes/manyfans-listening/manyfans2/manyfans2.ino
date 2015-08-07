// Define which pin to be used to communicate with Base pin of TIP120 transistors
int pins [9] = {2, 3, 6, 7, 8, 9, 10, 11, 12}; //11, ...

void setup()
{
  Serial.begin(9600);//initialize the serial communication
  
  for (int i = 0; i < 9; i++) {
    pinMode(pins[i], OUTPUT); // Set pin for output to control TIP120 Base pin
  }
  
}

void loop()
{
  if (Serial.available()) {
    for (int i = 0; i < 9; i++) {
      int motorValue = Serial.parseInt();
      digitalWrite(pins[i], motorValue); // send values to motor : By changing values from 0 to 255 you can control motor speed
      // For debugging: Send the value to the serial port, this will be read by processing
      Serial.write(motorValue); 
      Serial.write(", ");
    }
    Serial.write("\n");
  }
  delay(100);    // Wait 100ms for next reading
}


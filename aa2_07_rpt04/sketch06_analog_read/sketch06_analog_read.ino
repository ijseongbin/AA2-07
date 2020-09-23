void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print("AA07, Present V(0 ~ 5.0): ");
  float voltage = sensorValue*(5.0/1023.0);
  Serial.println(voltage);
  delay(10);
}

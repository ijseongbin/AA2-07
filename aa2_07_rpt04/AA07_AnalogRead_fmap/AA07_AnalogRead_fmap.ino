// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  //read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = f_map(sensorValue, 0, 1023, 0.0, 5.0);
  Serial.print("AA07, Present voltage (0.0 ~ 5.0)) : ");
  Serial.println(voltage);
  delay(1);
}
float f_map(long x, long in_min, long in_max, float out_min, float out_max)
{
  return (x-in_min)*(out_max-out_min) / (in_max-in_min) + out_min;
}

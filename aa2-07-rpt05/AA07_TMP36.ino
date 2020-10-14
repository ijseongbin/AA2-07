//
// AA05, TMP36 sensor
//

#define TEMP_INPUT 0
// or  int TEMP_INPUT = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   //getting the voltage reading from the temperature sensor
  int value = analogRead(TEMP_INPUT);
  Serial.print("AA05 value = ");
  Serial.print(value);
  Serial.print(" : ");

  float voltage = value * 5.0 * 1000; // in mV 
  voltage /=1023.0;
  // Print value
  Serial.print(voltage);
  Serial.print(" mV, ");

  //now print out the temperature
  float temperatureC = (voltage - 500) / 10;
  Serial.print(temperatureC);
  Serial.println(" degrees C");

  delay(500);
}

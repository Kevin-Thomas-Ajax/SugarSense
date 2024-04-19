// Pin number where the LED is connected
const int SENSOR_PIN = A0;

void setup() {
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(4, HIGH);

  // Read analog input from the transimpedance amplifier
  int sensorValue1 = analogRead(SENSOR_PIN);
  delay(1000);
  int sensorValue2 = analogRead(SENSOR_PIN);
  delay(1000);
  int sensorValue3 = analogRead(SENSOR_PIN);
  delay(1000);

  // Convert sensor value to glucose level
  float voltageOutput = ((sensorValue1 + sensorValue2 + sensorValue3)/3) * (5.0 / 1023.0);

  // Print sensor value (glucose level) to the serial monitor with 5 decimal places
  Serial.print("Sensor Value: ");
  float glucoseLevel = 293.1 * voltageOutput + 49.10 ;
  Serial.println(glucoseLevel, 5);

  delay(500);
}
#define IR_SENSOR_PIN 34

float getDistance(int sensorValue) {
  // Replace this with your calibrated curve
  return 123456.0 / (sensorValue - 45.0);
}

int getSmoothedReading(int pin, int samples = 10) {
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  return sum / samples;
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = getSmoothedReading(IR_SENSOR_PIN);
  float distance = getDistance(sensorValue);

  if (sensorValue > 100) {
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");
  }

  delay(200);
}

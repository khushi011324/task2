const int motionSensorPin = 2;
const int ledPin = 13;
volatile int motionValue = LOW;  // Volatile because it will be modified in an interrupt routine

void setup() {
  Serial.begin(9600);
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach the interrupt for motion sensor
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionSensorInterrupt, CHANGE);
}

void loop() {
  // Your main loop remains empty as the work is done in the interrupt
}

// Interrupt service routine for motion sensor
void motionSensorInterrupt() {
  motionValue = digitalRead(motionSensorPin);

  // Print motion sensor value to Serial Monitor
  Serial.print("Motion Sensor: ");
  Serial.println(motionValue == HIGH ? "Motion Detected" : "No Motion");

  // Update LED based on motion sensor value
  digitalWrite(ledPin, motionValue);
}

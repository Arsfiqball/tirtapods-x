#define PIN_LINE_SENSOR A8

void setup() {
  pinMode(PIN_LINE_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(PIN_LINE_SENSOR));
}

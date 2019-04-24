#define PIN_FLAME_INDICATOR 44
#define PIN_PHOTODIODE_A A0
#define PIN_PHOTODIODE_B A1
#define PIN_PHOTODIODE_C A2
#define PIN_PHOTODIODE_D A3
#define PIN_PHOTODIODE_E A4

namespace flame {
  bool is_right = false;
  bool is_left = false;
  bool is_center = false;
  unsigned long int state_lastRecord = 0;
  bool state_isIndicatorOn = false;

  void setup () {
    pinMode(PIN_FLAME_INDICATOR, OUTPUT);
  }

  void blinkIndicator () {
    if (millis() > state_lastRecord + 199) {
      state_lastRecord = millis();
      state_isIndicatorOn = !state_isIndicatorOn;
      if (state_isIndicatorOn) {
        digitalWrite(PIN_FLAME_INDICATOR, LOW);
      } else {
        digitalWrite(PIN_FLAME_INDICATOR, HIGH);
      }
    }
  }

  void update () {
    unsigned int flame_a = analogRead(PIN_PHOTODIODE_A);
    unsigned int flame_b = analogRead(PIN_PHOTODIODE_B);
    unsigned int flame_c = analogRead(PIN_PHOTODIODE_C);
    unsigned int flame_d = analogRead(PIN_PHOTODIODE_D);
    unsigned int flame_e = analogRead(PIN_PHOTODIODE_E);

    Serial.print("A:");
    Serial.print(flame_a);
    Serial.print(" B:");
    Serial.print(flame_b);
    Serial.print(" C:");
    Serial.print(flame_c);
    Serial.print(" D:");
    Serial.print(flame_d);
    Serial.print(" E:");
    Serial.println(flame_e);

    is_right = flame_b > 900;
    is_center = flame_c > 900;
    is_left = flame_d > 900;

    if (is_right || is_center || is_left) blinkIndicator();
    else digitalWrite(PIN_FLAME_INDICATOR, LOW);
  }
}

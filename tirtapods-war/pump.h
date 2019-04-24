#define PIN_PUMP 9

namespace pump {
  bool state_isON = false;

  void setup () {
    pinMode(PIN_PUMP, OUTPUT);
  }

  void on () {
    if (!state_isON) {
      digitalWrite(PIN_PUMP, LOW);
      state_isON = true;
    }
  }

  void off () {
    if (state_isON) {
      digitalWrite(PIN_PUMP, HIGH);
      state_isON = false;
    }
  }
}

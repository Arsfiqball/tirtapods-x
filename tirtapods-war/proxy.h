#define PIN_PROXIMITY 8

namespace proxy {
  bool isDetectingSomething = false;

  void setup () {
    pinMode(PIN_PROXIMITY, INPUT);
  }

  void update () {
    isDetectingSomething = digitalRead(PIN_PROXIMITY) == LOW;
  }
}

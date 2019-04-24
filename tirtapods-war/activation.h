#define PIN_START 42
#define PIN_STOP 40
#define PIN_SOUND_ACTIVATION 23

namespace activation {
  bool isON = false;

  void setup () {
    pinMode(PIN_START, INPUT_PULLUP);
    pinMode(PIN_STOP, INPUT_PULLUP);
    pinMode(PIN_SOUND_ACTIVATION, INPUT);
  }

  void update () {
    if (digitalRead(PIN_START) == LOW || digitalRead(PIN_SOUND_ACTIVATION) == LOW) {
      isON = true;
    }
  
    if (digitalRead(PIN_STOP) == LOW) {
      isON = false;
    }
  }
}

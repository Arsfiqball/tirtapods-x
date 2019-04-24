#include <Wire.h>
#include <LiquidCrystal_I2C.h>

namespace lcd {
  enum MessageID {
    BLANK,
    STANDBY,
    NORMALIZING,
    MOVING_FORWARD,
    MOVING_BACKWARD,
    SHIFTING_RIGHT,
    SHIFTING_LEFT,
    ROTATING_CW,
    ROTATING_CCW,
    TURNING_RIGHT,
    TURNING_LEFT,
    EXTINGUISHING,
    WALL_ON_RIGHT,
    WALL_ON_FRONT,
    WALL_ON_LEFT,
    THERE_IS_OBSTACLE,
    FIRE_ON_RIGHT,
    FIRE_ON_CENTER,
    FIRE_ON_LEFT,
    PATH_ON_RIGHT,
    PATH_ON_FRONT,
    PATH_ON_LEFT,
    NO_PATH
  };

  MessageID state_activeMessageIDs[2] = { BLANK, BLANK };

  LiquidCrystal_I2C lcd(0x27, 16, 2);

  void setup () {
    lcd.begin();
    lcd.backlight();
  }

  void message (int row, MessageID id) {
    if (row != 0 && row != 1) return;             // valid row is 0 and 1

    if (id != state_activeMessageIDs[row]) {
      state_activeMessageIDs[row] = id;           // update state
      lcd.setCursor(0, row);                      // set cursor to first column at selected row
      lcd.print(F("                     "));      // clear selected row
      lcd.setCursor(0, row);                      // set cursor back to first column
    } else {
      return;                                     // terminate because of no update
    }

    switch (id) {
      case BLANK:
        lcd.print(F(""));
        break;
      case STANDBY:
        lcd.print(F("ROBOT IS STANDBY"));
        break;
      case NORMALIZING:
        lcd.print(F("NORMALIZING LEGS"));
        break;
      case MOVING_FORWARD:
        lcd.print(F("MOVING FORWARD"));
        break;
      case MOVING_BACKWARD:
        lcd.print(F("MOVING BACKWARD"));
        break;
      case SHIFTING_RIGHT:
        lcd.print(F("SHIFTING RIGHT"));
        break;
      case SHIFTING_LEFT:
        lcd.print(F("SHIFTING LEFT"));
        break;
      case ROTATING_CW:
        lcd.print(F("ROTATING CW"));
        break;
      case ROTATING_CCW:
        lcd.print(F("ROTATING CCW"));
        break;
      case TURNING_RIGHT:
        lcd.print(F("TURNING RIGHT"));
        break;
      case TURNING_LEFT:
        lcd.print(F("TURNING LEFT"));
        break;
      case EXTINGUISHING:
        lcd.print(F("EXTINGUISHING"));
        break;
      case WALL_ON_RIGHT:
        lcd.print(F("WALL ON RIGHT"));
        break;
      case WALL_ON_FRONT:
        lcd.print(F("WALL ON FRONT"));
        break;
      case WALL_ON_LEFT:
        lcd.print(F("WALL ON LEFT"));
        break;
      case THERE_IS_OBSTACLE:
        lcd.print(F("THERE'S OBSTACLE"));
        break;
      case FIRE_ON_RIGHT:
        lcd.print(F("FIRE ON RIGHT"));
        break;
      case FIRE_ON_CENTER:
        lcd.print(F("FIRE ON CENTER"));
        break;
      case FIRE_ON_LEFT:
        lcd.print(F("FIRE ON LEFT"));
        break;
      case PATH_ON_RIGHT:
        lcd.print(F("PATH ON RIGHT"));
        break;
      case PATH_ON_FRONT:
        lcd.print(F("PATH ON FRONT"));
        break;
      case PATH_ON_LEFT:
        lcd.print(F("PATH ON LEFT"));
        break;
      case NO_PATH:
        lcd.print(F("NO PATH"));
        break;
    }
  }
}


#include "ping.h"
#include "proxy.h"
#include "flame.h"
#include "legs.h"
#include "pump.h"
#include "activation.h"
#include "lcd.h"

void setup () {
  ping::setup();
  proxy::setup();
  flame::setup();
  legs::setup();
  pump::setup();
  activation::setup();
  lcd::setup();

  Serial.begin(9600);
}

void loop () {
  activation::update();

  if (activation::isON) {
    ping::update();
    proxy::update();
    flame::update();

    if (!avoidWall()) return;
    if (flameDetection()) return;
    if (!avoidObstacle()) return;
    if (!getCloser2SRWR()) return;
    traceRoute();
  } else {
    if (activation::isMenu) {
      Serial.print("menu: ");
      Serial.println(activation::activeMenu);
      if (activation::isMenuChanged) lcd::clean();
      switch (activation::activeMenu) {
        case 0:
          lcd::justPrint(ping::debug(), ping::debug1());
          break;
        case 1:
          lcd::justPrint(flame::debug(), flame::debug1());
          break;
        case 2:
          lcd::justPrint(proxy::debug(), activation::debugSoundActivation());
          break;
        case 3:
          lcd::justPrint("Press start to", "extinguish");
          pump::activate(activation::isStartPushed);
          break;
        default:
          lcd::justPrint("== DEBUG MODE ==", "Press stop again");
      }
    } else {
      Serial.println("no menu");
      standBy();
    }
  }
}

void standBy () {
  if (legs::isStandby) {
    lcd::message(0, lcd::STANDBY);
    lcd::message(1, lcd::BLANK);
    return;
  }

  if (legs::isNormalized) {
    legs::standby();
    return;
  }

  lcd::message(0, lcd::NORMALIZING);
  lcd::message(1, lcd::BLANK);
  legs::normalize();
}

bool avoidObstacle () {
  if (proxy::isDetectingSomething && !ping::far_b && !ping::far_c && !ping::far_d) {
    lcd::message(0, lcd::THERE_IS_OBSTACLE);

    if (!legs::isNormalized) {
      legs::normalize();
      return false;
    }

    legs::ssc_rotateCCW_sync();
    legs::ssc_rotateCCW_sync();
    legs::ssc_rotateCCW_sync();
    legs::ssc_rotateCCW_sync();
    legs::ssc_rotateCCW_sync();

    return false;
  }

  return true;
}

bool avoidWall () {
  short int minPos = 0;
  short int maxPos = 8;
  bool minPosFound = false;
  bool maxPosFound = false;

  if (!minPosFound && ping::near_a) { minPos = 0; minPosFound = true; }
  if (!minPosFound && ping::near_b) { minPos = 2; minPosFound = true; }
  if (!minPosFound && ping::near_c) { minPos = 4; minPosFound = true; }
  if (!minPosFound && ping::near_d) { minPos = 6; minPosFound = true; }
  if (!minPosFound && ping::near_e) { minPos = 8; minPosFound = true; }

  if (!maxPosFound && ping::near_e) { maxPos = 8; maxPosFound = true; }
  if (!maxPosFound && ping::near_d) { maxPos = 6; maxPosFound = true; }
  if (!maxPosFound && ping::near_c) { maxPos = 4; maxPosFound = true; }
  if (!maxPosFound && ping::near_b) { maxPos = 2; maxPosFound = true; }
  if (!maxPosFound && ping::near_a) { maxPos = 0; maxPosFound = true; }

  if (!minPosFound || !maxPosFound) return true; // this means wall is successfully avoided, if it's not then continue below

  short int avg = (maxPos + minPos) / 2;

  if (avg < 1) {
    lcd::message(0, lcd::WALL_ON_RIGHT);
    lcd::message(1, lcd::SHIFTING_LEFT);
    legs::shiftLeft();
  } else if (1 <= avg && avg <= 3) {
    lcd::message(0, lcd::WALL_ON_RIGHT);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCW();
  } else if (3 < avg && avg < 5) {
    lcd::message(0, lcd::WALL_ON_FRONT);

    if ((maxPos - minPos) == 0) {
      lcd::message(1, lcd::MOVING_BACKWARD);
      legs::backward(); // wall surface is flat
    } else {
      lcd::message(1, lcd::ROTATING_CW);
      legs::rotateCW(); // wall surface detected is not flat
    }
  } else if (5 <= avg && avg <= 7) {
    lcd::message(0, lcd::WALL_ON_LEFT);
    lcd::message(1, lcd::ROTATING_CW);
    legs::rotateCW();
  } else if (avg > 7) {
    lcd::message(0, lcd::WALL_ON_LEFT);
    lcd::message(1, lcd::SHIFTING_RIGHT);
    legs::shiftRight();
  }

  return false;
}

bool flameDetection () {
  Serial.println(proxy::isDetectingSomething);

  if (flame::is_right && (ping::near_b || ping::near_a)) {
    lcd::message(0, lcd::FIRE_ON_RIGHT);
    lcd::message(1, lcd::SHIFTING_LEFT);
    legs::shiftLeft();
    return true;
  }

  if (flame::is_left && (ping::near_d || ping::near_e)) {
    lcd::message(0, lcd::FIRE_ON_LEFT);
    lcd::message(1, lcd::SHIFTING_RIGHT);
    legs::shiftRight();
    return true;
  }

  if (flame::is_right && !flame::is_left && !flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_RIGHT);
    lcd::message(1, lcd::ROTATING_CW);
    legs::rotateCW();
    return true;
  }

  if (flame::is_left && !flame::is_right && !flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_LEFT);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCW();
    return true;
  }

  if (flame::is_right && !flame::is_left && flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_RIGHT);
    lcd::message(1, lcd::ROTATING_CW);
    legs::rotateCWLess();
    return true;
  }

  if (flame::is_left && !flame::is_right && flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_LEFT);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCWLess();
    return true;
  }

  if (flame::is_center) {
    lcd::message(0, lcd::FIRE_ON_CENTER);

    if (ping::near_b) {
      lcd::message(1, lcd::ROTATING_CCW);
      legs::rotateCCWLess();
    } else if (ping::near_d) {
      lcd::message(1, lcd::ROTATING_CW);
      legs::rotateCWLess();
    } else {
      if (proxy::isDetectingSomething) {
        lcd::message(1, lcd::EXTINGUISHING);
        pump::extinguish(1000);
      } else {
        lcd::message(1, lcd::MOVING_FORWARD);
        legs::forward();
      }
    }

    return true;
  }

  return false;
}

bool getCloser2SRWR () {
  if (ping::far_a && !ping::far_b && !ping::isOnSRWR) {
    lcd::message(0, lcd::FOUND_SRWR);
    lcd::message(1, lcd::SHIFTING_RIGHT);
    legs::shiftRight();
    return false;
  }

  return true;
}

void traceRoute () {
  if (!ping::far_a && !ping::far_b) {
    lcd::message(0, lcd::PATH_ON_RIGHT);
    lcd::message(1, lcd::TURNING_RIGHT);
    legs::turnRight();
  } else if (ping::far_a && !ping::far_c) {
    lcd::message(0, lcd::PATH_ON_FRONT);
    lcd::message(1, lcd::MOVING_FORWARD);
    legs::forward();
  } else if (ping::far_a && ping::far_c && !ping::far_e) {
    lcd::message(0, lcd::PATH_ON_LEFT);
    lcd::message(1, lcd::TURNING_LEFT);
    legs::turnLeft();
  } else {
    lcd::message(0, lcd::NO_PATH);
    lcd::message(1, lcd::ROTATING_CCW);
    legs::rotateCCW();
  }
}

#include <SoftwareSerial.h>

namespace legs {
  bool isNormalized = false;
  bool isStandby = false;

  enum MoveType {
    STANDBY,
    NORMALIZE,
    FORWARD,
    BACKWARD,
    SHIFT_RIGHT,
    SHIFT_LEFT,
    ROTATE_CW,
    ROTATE_CCW,
    ROTATE_CW_LESS,
    ROTATE_CCW_LESS,
    TURN_RIGHT,
    TURN_LEFT
  };

  MoveType state_currentMove = NORMALIZE;
  unsigned short int state_step2keep = 0;
  unsigned long int state_lastMoveRecord = 0;
  unsigned short int state_nextStep = 0;
  bool state_isComboAUp = true;
  bool state_isComboBUp = true;

  SoftwareSerial com(19, 18); // RX, TX

  void setup () {
    com.begin(9600);
  }


  // START OF CODE GENERATED

  void ssc_standby () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2238 #6P2043 #12P1324 #13P2238 #14P2043 #24P1500 #25P727 #26P695 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P2148 #6P1999 #12P1324 #13P2148 #14P1999 #24P1500 #25P828 #26P744 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2323 #10P2055 #20P1374 #21P662 #22P857 #28P1526 #29P662 #30P930 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P2222 #10P2006 #20P1374 #21P752 #22P901 #28P1526 #29P752 #30P981 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1526 #5P2148 #6P1999 #12P1324 #13P2148 #14P1999 #24P1500 #25P828 #26P744 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1526 #5P1905 #6P1856 #12P1324 #13P1905 #14P1856 #24P1500 #25P1090 #26P897 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1450 #9P2222 #10P2006 #20P1374 #21P752 #22P901 #28P1526 #29P752 #30P981 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1450 #9P1960 #10P1853 #20P1374 #21P995 #22P1044 #28P1526 #29P995 #30P1146 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P2211 #10P1978 #12P1450 #13P1880 #14P1748 #20P1500 #21P811 #22P1026 #24P1313 #25P1092 #26P919 #28P1695 #29P719 #30P887 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P1958 #10P1831 #12P1450 #13P1880 #14P1748 #20P1500 #21P1020 #22P1152 #24P1313 #25P1092 #26P919 #28P1695 #29P991 #30P1071 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1400 #5P2089 #6P1874 #8P1637 #9P1958 #10P1831 #12P1155 #13P2181 #14P2080 #20P1205 #21P991 #22P978 #24P1687 #25P839 #26P772 #28P1400 #29P1020 #30P1272 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1400 #5P1880 #6P1748 #8P1637 #9P1958 #10P1831 #12P1155 #13P1909 #14P1922 #20P1205 #21P991 #22P978 #24P1687 #25P1092 #26P919 #28P1400 #29P1020 #30P1272 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1400 #5P1880 #6P1748 #8P1637 #9P2211 #10P1978 #12P1155 #13P1909 #14P1922 #20P1205 #21P719 #22P820 #24P1687 #25P1092 #26P919 #28P1400 #29P811 #30P1126 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1400 #5P1880 #6P1748 #8P1637 #9P1958 #10P1831 #12P1155 #13P1909 #14P1922 #20P1205 #21P991 #22P978 #24P1687 #25P1092 #26P919 #28P1400 #29P1020 #30P1272 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2181 #6P2080 #8P1263 #9P1958 #10P1831 #12P1450 #13P2089 #14P1874 #20P1500 #21P1020 #22P1152 #24P1313 #25P839 #26P772 #28P1695 #29P991 #30P1071 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P1958 #10P1831 #12P1450 #13P1880 #14P1748 #20P1500 #21P1020 #22P1152 #24P1313 #25P1092 #26P919 #28P1695 #29P991 #30P1071 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1605 #5P1865 #6P1705 #8P1450 #9P2252 #10P2092 #12P1245 #13P1865 #14P1705 #20P1295 #21P835 #22P1073 #24P1500 #25P1098 #26P832 #28P1605 #29P835 #30P1181 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1605 #5P1865 #6P1705 #8P1450 #9P1952 #10P1918 #12P1245 #13P1865 #14P1705 #20P1295 #21P1035 #22P1195 #24P1500 #25P1098 #26P832 #28P1605 #29P1035 #30P1322 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1470 #5P2179 #6P2073 #8P1450 #9P1926 #10P1687 #12P1380 #13P2179 #14P2073 #20P1430 #21P990 #22P984 #24P1500 #25P917 #26P937 #28P1470 #29P990 #30P1077 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1470 #5P1910 #6P1916 #8P1450 #9P1926 #10P1687 #12P1380 #13P1910 #14P1916 #20P1430 #21P990 #22P984 #24P1500 #25P1124 #26P1063 #28P1470 #29P990 #30P1077 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1470 #5P1910 #6P1916 #8P1450 #9P2133 #10P1813 #12P1380 #13P1910 #14P1916 #20P1430 #21P721 #22P827 #24P1500 #25P1124 #26P1063 #28P1470 #29P721 #30P895 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1470 #5P1910 #6P1916 #8P1450 #9P1926 #10P1687 #12P1380 #13P1910 #14P1916 #20P1430 #21P990 #22P984 #24P1500 #25P1124 #26P1063 #28P1470 #29P990 #30P1077 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1605 #5P2065 #6P1827 #8P1450 #9P1952 #10P1918 #12P1245 #13P2065 #14P1827 #20P1295 #21P1035 #22P1195 #24P1500 #25P798 #26P658 #28P1605 #29P1035 #30P1322 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1605 #5P1865 #6P1705 #8P1450 #9P1952 #10P1918 #12P1245 #13P1865 #14P1705 #20P1295 #21P1035 #22P1195 #24P1500 #25P1098 #26P832 #28P1605 #29P1035 #30P1322 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1894 #6P1799 #8P1308 #9P2216 #10P1990 #12P1513 #13P1907 #14P1865 #20P1205 #21P783 #22P968 #24P1642 #25P1091 #26P910 #28P1337 #29P748 #30P970 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1894 #6P1799 #8P1308 #9P1959 #10P1840 #12P1513 #13P1907 #14P1865 #20P1205 #21P1006 #22P1101 #24P1642 #25P1091 #26P910 #28P1337 #29P993 #30P1137 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1337 #5P2152 #6P2009 #8P1592 #9P1959 #10P1840 #12P1155 #13P2117 #14P1932 #20P1563 #21P993 #22P1035 #24P1358 #25P834 #26P760 #28P1695 #29P1006 #30P1213 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1337 #5P1907 #6P1865 #8P1592 #9P1959 #10P1840 #12P1155 #13P1894 #14P1799 #20P1563 #21P993 #22P1035 #24P1358 #25P1091 #26P910 #28P1695 #29P1006 #30P1213 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1337 #5P1907 #6P1865 #8P1592 #9P2216 #10P1990 #12P1155 #13P1894 #14P1799 #20P1563 #21P748 #22P891 #24P1358 #25P1091 #26P910 #28P1695 #29P783 #30P1058 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1337 #5P1907 #6P1865 #8P1592 #9P1959 #10P1840 #12P1155 #13P1894 #14P1799 #20P1563 #21P993 #22P1035 #24P1358 #25P1091 #26P910 #28P1695 #29P1006 #30P1213 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2117 #6P1932 #8P1308 #9P1959 #10P1840 #12P1513 #13P2152 #14P2009 #20P1205 #21P1006 #22P1101 #24P1642 #25P834 #26P760 #28P1337 #29P993 #30P1137 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1894 #6P1799 #8P1308 #9P1959 #10P1840 #12P1513 #13P1907 #14P1865 #20P1205 #21P1006 #22P1101 #24P1642 #25P1091 #26P910 #28P1337 #29P993 #30P1137 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1586 #5P1903 #6P1843 #8P1402 #9P2221 #10P2004 #12P1387 #13P1907 #14P1865 #20P1314 #21P759 #22P917 #24P1548 #25P1090 #26P899 #28P1463 #29P748 #30P970 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1586 #5P1903 #6P1843 #8P1402 #9P1960 #10P1851 #12P1387 #13P1907 #14P1865 #20P1314 #21P997 #22P1057 #24P1548 #25P1090 #26P899 #28P1463 #29P993 #30P1137 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2152 #6P2009 #8P1498 #9P1960 #10P1851 #12P1264 #13P2141 #14P1983 #20P1437 #21P993 #22P1035 #24P1452 #25P829 #26P746 #28P1586 #29P997 #30P1162 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1907 #6P1865 #8P1498 #9P1960 #10P1851 #12P1264 #13P1903 #14P1843 #20P1437 #21P993 #22P1035 #24P1452 #25P1090 #26P899 #28P1586 #29P997 #30P1162 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1463 #5P1907 #6P1865 #8P1498 #9P2221 #10P2004 #12P1264 #13P1903 #14P1843 #20P1437 #21P748 #22P891 #24P1452 #25P1090 #26P899 #28P1586 #29P759 #30P1000 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1463 #5P1907 #6P1865 #8P1498 #9P1960 #10P1851 #12P1264 #13P1903 #14P1843 #20P1437 #21P993 #22P1035 #24P1452 #25P1090 #26P899 #28P1586 #29P997 #30P1162 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1586 #5P2141 #6P1983 #8P1402 #9P1960 #10P1851 #12P1387 #13P2152 #14P2009 #20P1314 #21P997 #22P1057 #24P1548 #25P829 #26P746 #28P1463 #29P993 #30P1137 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1586 #5P1903 #6P1843 #8P1402 #9P1960 #10P1851 #12P1387 #13P1907 #14P1865 #20P1314 #21P997 #22P1057 #24P1548 #25P1090 #26P899 #28P1463 #29P993 #30P1137 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P2211 #10P1978 #12P1450 #13P1880 #14P1748 #20P1500 #21P811 #22P1026 #24P1313 #25P1092 #26P919 #28P1695 #29P719 #30P887 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P1958 #10P1831 #12P1450 #13P1880 #14P1748 #20P1500 #21P1020 #22P1152 #24P1313 #25P1092 #26P919 #28P1695 #29P991 #30P1071 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1463 #5P2152 #6P2009 #8P1498 #9P1960 #10P1851 #12P1264 #13P2141 #14P1983 #20P1437 #21P993 #22P1035 #24P1452 #25P829 #26P746 #28P1586 #29P997 #30P1162 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1463 #5P1907 #6P1865 #8P1498 #9P1960 #10P1851 #12P1264 #13P1903 #14P1843 #20P1437 #21P993 #22P1035 #24P1452 #25P1090 #26P899 #28P1586 #29P997 #30P1162 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P2211 #10P1978 #12P1450 #13P1880 #14P1748 #20P1500 #21P811 #22P1026 #24P1313 #25P1092 #26P919 #28P1695 #29P719 #30P887 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1695 #5P1909 #6P1922 #8P1263 #9P1958 #10P1831 #12P1450 #13P1880 #14P1748 #20P1500 #21P1020 #22P1152 #24P1313 #25P1092 #26P919 #28P1695 #29P991 #30P1071 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1695 #5P2117 #6P1932 #8P1308 #9P1959 #10P1840 #12P1513 #13P2152 #14P2009 #20P1205 #21P1006 #22P1101 #24P1642 #25P834 #26P760 #28P1337 #29P993 #30P1137 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1695 #5P1894 #6P1799 #8P1308 #9P1959 #10P1840 #12P1513 #13P1907 #14P1865 #20P1205 #21P1006 #22P1101 #24P1642 #25P1091 #26P910 #28P1337 #29P993 #30P1137 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  // END OF GENERATED

  void move (MoveType id) {
    if (millis() - state_lastMoveRecord > 199) {
      state_lastMoveRecord = millis();

      if (state_currentMove != NORMALIZE || (state_currentMove == NORMALIZE && (state_isComboAUp || state_isComboBUp))) {
        isNormalized = false;
      }

      if (state_currentMove != STANDBY) {
        isStandby = false;
      }

      if (state_step2keep > 0) {
        state_step2keep = state_step2keep - 1;
      } else {
        state_currentMove = id;
      }

      switch (state_currentMove) {
        case STANDBY:
          ssc_standby();
          break;
        case NORMALIZE:
          ssc_normalize();
          break;
        case FORWARD:
          ssc_forward();
          break;
        case BACKWARD:
          ssc_backward();
          break;
        case SHIFT_RIGHT:
          ssc_shiftRight();
          break;
        case SHIFT_LEFT:
          ssc_shiftLeft();
          break;
        case ROTATE_CW:
          ssc_rotateCW();
          break;
        case ROTATE_CCW:
          ssc_rotateCCW();
          break;
        case ROTATE_CW_LESS:
          ssc_rotateCWLess();
          break;
        case ROTATE_CCW_LESS:
          ssc_rotateCCWLess();
          break;
        case TURN_RIGHT:
          ssc_turnRight();
          break;
        case TURN_LEFT:
          ssc_turnLeft();
          break;
      }
    }
  }

  void keep (int num) {
    if (state_step2keep < 1) {
      state_step2keep = num;
    }
  }

  void force () {
    state_step2keep = 0;
  }

  void standby () {
    move(STANDBY);

    if (state_currentMove == STANDBY && !state_isComboAUp && !state_isComboBUp) {
      isStandby = true;
    }
  }

  void normalize () {
    if (state_currentMove != NORMALIZE) {
      if (state_isComboAUp) {
        state_nextStep = 1;
      } else if (state_isComboBUp) {
        state_nextStep = 3;
      }
    }

    move(NORMALIZE);

    if (state_currentMove == NORMALIZE && !state_isComboAUp && !state_isComboBUp) {
      isNormalized = true;
    }
  }

  void forward () {
    move(FORWARD);
  }

  void backward () {
    move(BACKWARD);
  }

  void shiftRight () {
    move(SHIFT_RIGHT);
  }

  void shiftLeft () {
    move(SHIFT_LEFT);
  }

  void rotateCW () {
    move(ROTATE_CW);
  }

  void rotateCCW () {
    move(ROTATE_CCW);
  }

  void rotateCWLess () {
    move(ROTATE_CW_LESS);
  }

  void rotateCCWLess () {
    move(ROTATE_CCW_LESS);
  }

  void turnRight () {
    move(TURN_RIGHT);
  }

  void turnLeft () {
    move(TURN_LEFT);
  }
}

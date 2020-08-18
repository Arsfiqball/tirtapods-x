#include <SoftwareSerial.h>

namespace legs {
  bool isNormalized = false;
  bool isStandby = false;

  enum MoveType {
    STANDBY,
    NORMALIZE,
    FORWARD,
    FORWARD_LOW,
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
  unsigned short int state_endStep = 3;

  SoftwareSerial com(19, 18); // RX, TX

  void setup () {
    com.begin(9600);
  }


  // START OF CODE GENERATED

  void ssc_standby () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1563 #5P2168 #6P2045 #8P1400 #9P2266 #10P2110 #12P1354 #13P2001 #14P2047 #20P1374 #21P786 #22P856 #24P1545 #25P903 #26P704 #28P1488 #29P732 #30P800 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1563 #5P2168 #6P2045 #8P1400 #9P2266 #10P2110 #12P1354 #13P2001 #14P2047 #20P1374 #21P786 #22P856 #24P1545 #25P903 #26P704 #28P1488 #29P732 #30P800 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1563 #5P2168 #6P2045 #8P1400 #9P2266 #10P2110 #12P1354 #13P2001 #14P2047 #20P1374 #21P786 #22P856 #24P1545 #25P903 #26P704 #28P1488 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1563 #5P2168 #6P2045 #8P1400 #9P2266 #10P2110 #12P1354 #13P2001 #14P2047 #20P1374 #21P786 #22P856 #24P1545 #25P903 #26P704 #28P1488 #29P732 #30P800 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1563 #5P2168 #6P2045 #12P1354 #13P2001 #14P2047 #24P1545 #25P903 #26P704 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1563 #5P1833 #6P1842 #12P1354 #13P1700 #14P1835 #24P1545 #25P1241 #26P914 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#8P1400 #9P2266 #10P2110 #20P1374 #21P786 #22P856 #28P1488 #29P732 #30P800 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#8P1400 #9P1892 #10P1870 #20P1374 #21P1093 #22P1052 #28P1488 #29P1067 #30P1024 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_normalize_sync () {
    com.println(F("#4P1563 #5P2168 #6P2045 #12P1354 #13P2001 #14P2047 #24P1545 #25P903 #26P704 T200")); delay(200);
    com.println(F("#4P1563 #5P1833 #6P1842 #12P1354 #13P1700 #14P1835 #24P1545 #25P1241 #26P914 T200")); delay(200);
    com.println(F("#8P1400 #9P2266 #10P2110 #20P1374 #21P786 #22P856 #28P1488 #29P732 #30P800 T200")); delay(200);
    com.println(F("#8P1400 #9P1892 #10P1870 #20P1374 #21P1093 #22P1052 #28P1488 #29P1067 #30P1024 T200")); delay(200);
  }

  void ssc_forward_low () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1674 #5P2191 #6P2108 #8P1272 #9P2260 #10P2094 #12P1460 #13P1967 #14P1957 #20P1472 #21P821 #22P940 #24P1416 #25P908 #26P718 #28P1614 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1674 #5P2191 #6P2108 #8P1272 #9P2260 #10P2094 #12P1460 #13P1967 #14P1957 #20P1472 #21P821 #22P940 #24P1416 #25P908 #26P718 #28P1614 #29P709 #30P731 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1475 #5P2129 #6P1958 #8P1528 #9P2260 #10P2094 #12P1221 #13P2022 #14P2113 #20P1251 #21P764 #22P796 #24P1674 #25P908 #26P718 #28P1388 #29P771 #30P896 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1475 #5P2129 #6P1958 #8P1528 #9P2260 #10P2094 #12P1221 #13P2022 #14P2113 #20P1251 #21P764 #22P796 #24P1674 #25P908 #26P718 #28P1388 #29P771 #30P896 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P2260 #10P2094 #12P1460 #13P1695 #14P1763 #20P1472 #21P821 #22P940 #24P1416 #25P1239 #26P924 #28P1614 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P1894 #10P1858 #12P1460 #13P1695 #14P1763 #20P1472 #21P1098 #22P1119 #24P1416 #25P1239 #26P924 #28P1614 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1475 #5P2129 #6P1958 #8P1528 #9P1894 #10P1858 #12P1221 #13P2022 #14P2113 #20P1251 #21P1099 #22P1008 #24P1674 #25P908 #26P718 #28P1388 #29P1072 #30P1100 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1475 #5P1828 #6P1772 #8P1528 #9P1894 #10P1858 #12P1221 #13P1695 #14P1883 #20P1251 #21P1099 #22P1008 #24P1674 #25P1239 #26P924 #28P1388 #29P1072 #30P1100 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_forward_sync () {
    com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P2260 #10P2094 #12P1460 #13P1695 #14P1763 #20P1472 #21P821 #22P940 #24P1416 #25P1239 #26P924 #28P1614 #29P709 #30P731 T200")); delay(200);
    com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P1894 #10P1858 #12P1460 #13P1695 #14P1763 #20P1472 #21P1098 #22P1119 #24P1416 #25P1239 #26P924 #28P1614 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1475 #5P2129 #6P1958 #8P1528 #9P1894 #10P1858 #12P1221 #13P2022 #14P2113 #20P1251 #21P1099 #22P1008 #24P1674 #25P908 #26P718 #28P1388 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1475 #5P1828 #6P1772 #8P1528 #9P1894 #10P1858 #12P1221 #13P1695 #14P1883 #20P1251 #21P1099 #22P1008 #24P1674 #25P1239 #26P924 #28P1388 #29P1072 #30P1100 T200")); delay(200);
  }

  void ssc_backward () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1475 #5P1828 #6P1772 #8P1528 #9P2260 #10P2094 #12P1221 #13P1695 #14P1883 #20P1251 #21P764 #22P796 #24P1674 #25P1239 #26P924 #28P1388 #29P771 #30P896 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1475 #5P1828 #6P1772 #8P1528 #9P1894 #10P1858 #12P1221 #13P1695 #14P1883 #20P1251 #21P1099 #22P1008 #24P1674 #25P1239 #26P924 #28P1388 #29P1072 #30P1100 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1674 #5P2191 #6P2108 #8P1272 #9P1894 #10P1858 #12P1460 #13P1967 #14P1957 #20P1472 #21P1098 #22P1119 #24P1416 #25P908 #26P718 #28P1614 #29P1073 #30P973 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P1894 #10P1858 #12P1460 #13P1695 #14P1763 #20P1472 #21P1098 #22P1119 #24P1416 #25P1239 #26P924 #28P1614 #29P1073 #30P973 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_backward_sync () {
    com.println(F("#4P1475 #5P1828 #6P1772 #8P1528 #9P2260 #10P2094 #12P1221 #13P1695 #14P1883 #20P1251 #21P764 #22P796 #24P1674 #25P1239 #26P924 #28P1388 #29P771 #30P896 T200")); delay(200);
    com.println(F("#4P1475 #5P1828 #6P1772 #8P1528 #9P1894 #10P1858 #12P1221 #13P1695 #14P1883 #20P1251 #21P1099 #22P1008 #24P1674 #25P1239 #26P924 #28P1388 #29P1072 #30P1100 T200")); delay(200);
    com.println(F("#4P1674 #5P2191 #6P2108 #8P1272 #9P1894 #10P1858 #12P1460 #13P1967 #14P1957 #20P1472 #21P1098 #22P1119 #24P1416 #25P908 #26P718 #28P1614 #29P1073 #30P973 T200")); delay(200);
    com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P1894 #10P1858 #12P1460 #13P1695 #14P1763 #20P1472 #21P1098 #22P1119 #24P1416 #25P1239 #26P924 #28P1614 #29P1073 #30P973 T200")); delay(200);
  }

  void ssc_shiftRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1634 #5P1814 #6P1704 #8P1400 #9P2289 #10P2200 #12P1269 #13P1683 #14P1693 #20P1295 #21P856 #22P1017 #24P1545 #25P1262 #26P861 #28P1569 #29P809 #30P984 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1634 #5P1814 #6P1704 #8P1400 #9P1868 #10P1930 #12P1269 #13P1683 #14P1693 #20P1295 #21P1111 #22P1184 #24P1545 #25P1262 #26P861 #28P1569 #29P1086 #30P1175 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1513 #5P2194 #6P2117 #8P1400 #9P1884 #10P1708 #12P1414 #13P2025 #14P2121 #20P1430 #21P1100 #22P1002 #24P1545 #25P978 #26P883 #28P1432 #29P1074 #30P967 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1513 #5P1826 #6P1894 #8P1400 #9P1884 #10P1708 #12P1414 #13P1693 #14P1889 #20P1430 #21P1100 #22P1002 #24P1545 #25P1248 #26P1055 #28P1432 #29P1074 #30P967 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_shiftLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1513 #5P1826 #6P1894 #8P1400 #9P2182 #10P1904 #12P1414 #13P1693 #14P1889 #20P1430 #21P761 #22P788 #24P1545 #25P1248 #26P1055 #28P1432 #29P706 #30P722 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1513 #5P1826 #6P1894 #8P1400 #9P1884 #10P1708 #12P1414 #13P1693 #14P1889 #20P1430 #21P1100 #22P1002 #24P1545 #25P1248 #26P1055 #28P1432 #29P1074 #30P967 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1634 #5P2091 #6P1879 #8P1400 #9P1868 #10P1930 #12P1269 #13P1932 #14P1874 #20P1295 #21P1111 #22P1184 #24P1545 #25P882 #26P625 #28P1569 #29P1086 #30P1175 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1634 #5P1814 #6P1704 #8P1400 #9P1868 #10P1930 #12P1269 #13P1683 #14P1693 #20P1295 #21P1111 #22P1184 #24P1545 #25P1262 #26P861 #28P1569 #29P1086 #30P1175 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P2260 #10P2094 #12P1559 #13P1700 #14P1843 #20P1205 #21P811 #22P919 #24P1674 #25P1239 #26P924 #28P1295 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P1894 #10P1858 #12P1559 #13P1700 #14P1843 #20P1205 #21P1096 #22P1101 #24P1674 #25P1239 #26P924 #28P1295 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1393 #5P2172 #6P2055 #8P1528 #9P1894 #10P1858 #12P1171 #13P1976 #14P1980 #20P1563 #21P1094 #22P1045 #24P1416 #25P908 #26P718 #28P1661 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P1894 #10P1858 #12P1171 #13P1698 #14P1782 #20P1563 #21P1094 #22P1045 #24P1416 #25P1239 #26P924 #28P1661 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCW_sync () {
    com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P2260 #10P2094 #12P1559 #13P1700 #14P1843 #20P1205 #21P811 #22P919 #24P1674 #25P1239 #26P924 #28P1295 #29P728 #30P790 T200")); delay(200);
    com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P1894 #10P1858 #12P1559 #13P1700 #14P1843 #20P1205 #21P1096 #22P1101 #24P1674 #25P1239 #26P924 #28P1295 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1393 #5P2172 #6P2055 #8P1528 #9P1894 #10P1858 #12P1171 #13P1976 #14P1980 #20P1563 #21P1094 #22P1045 #24P1416 #25P908 #26P718 #28P1661 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P1894 #10P1858 #12P1171 #13P1698 #14P1782 #20P1563 #21P1094 #22P1045 #24P1416 #25P1239 #26P924 #28P1661 #29P1069 #30P1080 T200")); delay(200);
  }

  void ssc_rotateCCW () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P2260 #10P2094 #12P1171 #13P1698 #14P1782 #20P1563 #21P782 #22P847 #24P1416 #25P1239 #26P924 #28P1661 #29P760 #30P871 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P1894 #10P1858 #12P1171 #13P1698 #14P1782 #20P1563 #21P1094 #22P1045 #24P1416 #25P1239 #26P924 #28P1661 #29P1069 #30P1080 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1716 #5P2140 #6P1981 #8P1272 #9P1894 #10P1858 #12P1559 #13P2004 #14P2057 #20P1205 #21P1096 #22P1101 #24P1674 #25P908 #26P718 #28P1295 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P1894 #10P1858 #12P1559 #13P1700 #14P1843 #20P1205 #21P1096 #22P1101 #24P1674 #25P1239 #26P924 #28P1295 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCW_sync () {
    com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P2260 #10P2094 #12P1171 #13P1698 #14P1782 #20P1563 #21P782 #22P847 #24P1416 #25P1239 #26P924 #28P1661 #29P760 #30P871 T200")); delay(200);
    com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P1894 #10P1858 #12P1171 #13P1698 #14P1782 #20P1563 #21P1094 #22P1045 #24P1416 #25P1239 #26P924 #28P1661 #29P1069 #30P1080 T200")); delay(200);
    com.println(F("#4P1716 #5P2140 #6P1981 #8P1272 #9P1894 #10P1858 #12P1559 #13P2004 #14P2057 #20P1205 #21P1096 #22P1101 #24P1674 #25P908 #26P718 #28P1295 #29P1067 #30P1016 T200")); delay(200);
    com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P1894 #10P1858 #12P1559 #13P1700 #14P1843 #20P1205 #21P1096 #22P1101 #24P1674 #25P1239 #26P924 #28P1295 #29P1067 #30P1016 T200")); delay(200);
  }

  void ssc_rotateCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1617 #5P1833 #6P1830 #8P1357 #9P2265 #10P2108 #12P1421 #13P1700 #14P1843 #20P1314 #21P792 #22P871 #24P1589 #25P1241 #26P915 #28P1425 #29P728 #30P790 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1617 #5P1833 #6P1830 #8P1357 #9P1892 #10P1869 #12P1421 #13P1700 #14P1843 #20P1314 #21P1093 #22P1064 #24P1589 #25P1241 #26P915 #28P1425 #29P1067 #30P1016 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1507 #5P2172 #6P2055 #8P1443 #9P1892 #10P1869 #12P1290 #13P1995 #14P2031 #20P1437 #21P1094 #22P1045 #24P1501 #25P903 #26P706 #28P1549 #29P1067 #30P1037 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1507 #5P1833 #6P1849 #8P1443 #9P1892 #10P1869 #12P1290 #13P1700 #14P1823 #20P1437 #21P1094 #22P1045 #24P1501 #25P1241 #26P915 #28P1549 #29P1067 #30P1037 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_rotateCCWLess () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1507 #5P1833 #6P1849 #8P1443 #9P2265 #10P2108 #12P1290 #13P1700 #14P1823 #20P1437 #21P782 #22P847 #24P1501 #25P1241 #26P915 #28P1549 #29P739 #30P817 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1507 #5P1833 #6P1849 #8P1443 #9P1892 #10P1869 #12P1290 #13P1700 #14P1823 #20P1437 #21P1094 #22P1045 #24P1501 #25P1241 #26P915 #28P1549 #29P1067 #30P1037 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1617 #5P2161 #6P2030 #8P1357 #9P1892 #10P1869 #12P1421 #13P2004 #14P2057 #20P1314 #21P1093 #22P1064 #24P1589 #25P903 #26P706 #28P1425 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1617 #5P1833 #6P1830 #8P1357 #9P1892 #10P1869 #12P1421 #13P1700 #14P1843 #20P1314 #21P1093 #22P1064 #24P1589 #25P1241 #26P915 #28P1425 #29P1067 #30P1016 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnRight () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P2260 #10P2094 #12P1460 #13P1695 #14P1763 #20P1472 #21P821 #22P940 #24P1416 #25P1239 #26P924 #28P1614 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P1894 #10P1858 #12P1460 #13P1695 #14P1763 #20P1472 #21P1098 #22P1119 #24P1416 #25P1239 #26P924 #28P1614 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1393 #5P2172 #6P2055 #8P1528 #9P1894 #10P1858 #12P1171 #13P1976 #14P1980 #20P1563 #21P1094 #22P1045 #24P1416 #25P908 #26P718 #28P1661 #29P1069 #30P1080 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1393 #5P1833 #6P1849 #8P1528 #9P1894 #10P1858 #12P1171 #13P1698 #14P1782 #20P1563 #21P1094 #22P1045 #24P1416 #25P1239 #26P924 #28P1661 #29P1069 #30P1080 T200"));
        state_isComboAUp = false;
        state_nextStep = 0;
        break;
    }
  }

  void ssc_turnLeft () {
    switch (state_nextStep) {
      case 0:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P2260 #10P2094 #12P1460 #13P1695 #14P1763 #20P1472 #21P821 #22P940 #24P1416 #25P1239 #26P924 #28P1614 #29P709 #30P731 T200"));
        state_isComboBUp = true;
        state_nextStep = 1;
        break;
      case 1:
        com.println(F("#4P1674 #5P1827 #6P1888 #8P1272 #9P1894 #10P1858 #12P1460 #13P1695 #14P1763 #20P1472 #21P1098 #22P1119 #24P1416 #25P1239 #26P924 #28P1614 #29P1073 #30P973 T200"));
        state_isComboBUp = false;
        state_nextStep = 2;
        break;
      case 2:
        com.println(F("#4P1716 #5P2140 #6P1981 #8P1272 #9P1894 #10P1858 #12P1559 #13P2004 #14P2057 #20P1205 #21P1096 #22P1101 #24P1674 #25P908 #26P718 #28P1295 #29P1067 #30P1016 T200"));
        state_isComboAUp = true;
        state_nextStep = 3;
        break;
      case 3:
        com.println(F("#4P1716 #5P1831 #6P1791 #8P1272 #9P1894 #10P1858 #12P1559 #13P1700 #14P1843 #20P1205 #21P1096 #22P1101 #24P1674 #25P1239 #26P924 #28P1295 #29P1067 #30P1016 T200"));
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
        case FORWARD_LOW:
          ssc_forward_low();
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
    if (state_currentMove == STANDBY) isStandby = true;
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

  void forward (bool low = false) {
    if (low) move(FORWARD_LOW);
    else move(FORWARD);
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

  void rotateCW (unsigned int keep = 0) {
    if (keep > 0) {
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < keep) {
        move(ROTATE_CW);
        currentCounter = millis();
      }
    } else {
      move(ROTATE_CW);
    }
  }

  void rotateCCW (unsigned int keep = 0) {
    if (keep > 0) {
      unsigned int startCounter = millis();
      unsigned int currentCounter = millis();
      while ((currentCounter - startCounter) < keep) {
        move(ROTATE_CCW);
        currentCounter = millis();
      }
    } else {
      move(ROTATE_CCW);
    }
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

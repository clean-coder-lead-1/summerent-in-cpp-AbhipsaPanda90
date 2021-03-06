#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"


TEST_CASE("Test 1 infers breach without contoller according to low limits") {
  REQUIRE(checkAndAlertWithoutController(31380513, 12) == BREACH_TYPE_TOO_LOW);
}


TEST_CASE("Test 2 infers breach without contoller according to high limits") {
  REQUIRE(checkAndAlertWithoutController(30586704, 85) == BREACH_TYPE_TOO_HIGH);
}


TEST_CASE("Test 3 infers breach with contoller according to low limits") {
  REQUIRE(checkAndAlertWithController(30586704, 25) == BREACH_TYPE_TOO_LOW);
}


TEST_CASE("Test 4 infers breach with contoller according to high limits") {
  REQUIRE(checkAndAlertWithController(34109704, 90) == BREACH_TYPE_TOO_HIGH);
}


TEST_CASE("Test 5 infers breach with contoller with unknown cooling type") {
  REQUIRE(checkAndAlertWithController(31530531, 90) == BREACH_TYPE_UNKNOWN);
}

TEST_CASE("Test 6 infers breach without contoller with unknown battery type") {
  REQUIRE(checkAndAlertWithoutController(34649247, 50) == BREACH_TYPE_UNKNOWN);
}

TEST_CASE("Test 7 infers breach with contoller according to normal limits") {
  REQUIRE(checkAndAlertWithController(31380513, 42) == BREACH_TYPE_NORMAL);
}

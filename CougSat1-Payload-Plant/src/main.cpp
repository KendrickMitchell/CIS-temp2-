#include "main.h"

void setup() {
  bme280_setup();
}

void loop() {
  bme280_print_serial();
}
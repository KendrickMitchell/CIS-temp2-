#include <wrapper.h>
#include <Arduino.h>

void setup() {
  setup_camera(); // setup arducam
  setup_bme280(); // setup humidity/pressure/temp sensor

  single_camera(); // take picture, send data serially
}

void loop() {
  loop_bme280(); // continuously read and send data serially
}

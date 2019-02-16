#ifndef MAIN_H
#define MAIN_H

#define PIN_SCK D13
#define PIN_MISO D12
#define PIN_MOSI D11
#define PIN_CS D7

// Includes
#include <Wire.h>
#include <SPI.h>

// Declarations
void bme280_setup();
void bme280_print_serial();
void setup_camera();
void single_camera();
 
#endif /* MAIN_H */
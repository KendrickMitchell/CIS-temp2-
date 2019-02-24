#ifndef BME280_H
#define BME280_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

#define I2C_SLAVE_ADDR 0x62
#define I2C_MASTER_ADDR 0x63

// Declarations
void bme280_setup();
void bme280_loop();
void bme280_print_serial();
void bme280_receive_event(int bytecount);
void bme280_request_event();

#endif /* MAIN_H */
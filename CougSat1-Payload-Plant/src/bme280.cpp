#include <wrapper.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
unsigned long delayTime;

void setup_bme280() {
    Serial.begin(115200);
    bool status;
    
    status = bme.begin();  // check i2c connection
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
    
    delayTime = 1000;

    delay(100); // let sensor boot up
}

void single_bme280() { // will be modified for to transmit over i2c
    printValues();
    delay(delayTime);
}


/*
 BELOW FUNTIONS USED FOR TESTING:
 */
void loop_bme280() { 
    printValues();
    delay(delayTime);
}

void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}
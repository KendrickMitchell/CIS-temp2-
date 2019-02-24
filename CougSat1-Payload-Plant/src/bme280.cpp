#include "bme280.h"

struct i2c_capture {
  float temperature;
  float pressure;
  float altitude;
  float humidity;
};

Adafruit_BME280 bme;
struct i2c_capture i2c_data;
char i2c_bytes[10];

void bme280_setup() {
  bool status;

  status = bme.begin();

  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // save data from sensor before initializing i2c connection as slave
  i2c_data.temperature = bme.readTemperature();
  i2c_data.pressure = bme.readPressure() / 100.0F;
  i2c_data.altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  i2c_data.humidity = bme.readHumidity();

  delay(500);

  Wire.begin(I2C_SLAVE_ADDR); // addr 0x62
  Wire.onReceive(bme280_receive_event);
  Wire.onRequest(bme280_request_event);
  Serial.begin(9600);
}

void bme280_receive_event(int bytecount) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);
  }
  
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);
}

void bme280_request_event() {
  dtostrf(i2c_data.temperature, 3, 2, i2c_bytes);

  Wire.beginTransmission(I2C_MASTER_ADDR);

  Wire.write(i2c_bytes);
}

void bme280_print_serial() { // for reading the sensor
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
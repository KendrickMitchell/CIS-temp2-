/*
 * Configure the wrapper parameters here.
 */

// SPI
#define CONFIG_SCK 13
#define CONFIG_MISO 12
#define CONFIG_MOSI 11
#define CONFIG_CS 7

// Misc BME280 variables
#define SEALEVELPRESSURE_HPA 1013.25


/*
 * Functions
 */

// Camera
void setup_camera();
void single_camera();
void setup_bme280();
void single_bme280();
void loop_bme280();
void printValues();
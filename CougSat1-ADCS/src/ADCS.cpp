/******************************************************************************
 * Copyright (c) 2018 by Cougs in Space - Washington State University         *
 * Cougs in Space website: cis.vcea.wsu.edu                                   *
 *                                                                            *
 * This file is a part of flight and/or ground software for Cougs in Space's  *
 * satellites. This file is proprietary and confidential.                     *
 * Unauthorized copying of this file, via any medium is strictly prohibited.  *
 ******************************************************************************/
/**
 * @file ADCS.cpp
 * @Worked on by Kendrick Mitchell and Haorui Zhang 
 * @Feb 3rd 2019 
 *
 *
 * ADCS Tasks:
 *	-Initialize subsystems
 *  -Read 4x IMUs
 *  -Read 1x GPS
	-Reach out to hbridge, provide it a PWM duty cycle signal to tell it how much we want it to run and	which direction
	-Read thermistor of magnetorquer
	-Get power info from IHU
	-Photodiodes?
 */
#include "ADCS.h"


uint8_t ADCS::OrientationDataRequest(char data[]){

char command[1] = {

   0x01

 };

if (this->i2c.write(I2C_ADDR_ADCS, command, 1) != 0) {

   printf("IHU<->ADCS OrientationDataRequest: write error\n");



   return ERROR_NACK;

 }

if (this->i2c.read(I2C_ADDR_ADCS, data, 8) != 0) {

   printf("IHU<->ADCS OrientationDataRequest: read error\n");

   

   return ERROR_NACK;

 }



 return ERROR_SUCCESS;
}



uint8_t ADCS::CoilControlDataRequest(char data[]){

char command[1] = {

   0x03

 };

if (this->i2c.write(I2C_ADDR_ADCS, command, 1) != 0) {

   printf("IHU<->ADCS CoilControlDataRequest: write error\n");



   return ERROR_NACK;

 }

if (this->i2c.read(I2C_ADDR_ADCS, data, 6) != 0) {

   printf("IHU<->ADCS CoilControlDataRequest: read error\n");

   

   return ERROR_NACK;

 }



 return ERROR_SUCCESS;
}


////
uint8_t ADCS::OrientationCommands(char data[]){

char command[1] = {

   0x05

 };

if (this->i2c.write(I2C_ADDR_ADCS, command, 7) != 0) {

   printf("IHU<->ADCS OrientationCommands: write error\n");



   return ERROR_NACK;

 }

/*if (this->i2c.read(I2C_ADDR_ADCS, data, 6) != 0) {

   printf("IHU<->ADCS OrientationCommands: read error\n");

   

   return ERROR_NACK;

 }*/



 return ERROR_SUCCESS;
}
//////////////

uint8_t ADCS::SatelliteManeuversforSpace(char data[]){

char command[1] = {

   0x07:Camera

 };

if (this->i2c.write(I2C_ADDR_ADCS, command, 9) != 0) {

   printf("IHU<->ADCS SatelliteManeuversforSpace: write error\n");



   return ERROR_NACK;

 }

/*if (this->i2c.read(I2C_ADDR_ADCS, data, 6) != 0) {

   printf("IHU<->ADCS SatelliteManeuversforSpace: read error\n");

   

   return ERROR_NACK;

 }*/



 return ERROR_SUCCESS;
}
////////////////////////////////////

uint8_t ADCS::Drift(char data[]){

char command[1] = {

   0x09

 };

if (this->i2c.write(I2C_ADDR_ADCS, command, 1) != 0) {

   printf("IHU<->ADCS Draft: write error\n");



   return ERROR_NACK;

 }

/*if (this->i2c.read(I2C_ADDR_ADCS, data, 1) != 0) {

   printf("IHU<->ADCS Drift: read error\n");

   

   return ERROR_NACK;

 }*/



 return ERROR_SUCCESS;
}
///////////////////////////////////////





 
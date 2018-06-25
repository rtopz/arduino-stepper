#include <Arduino.h>
#include "sensor.h"

sensor::sensor(int sSigPin) {
	sensorSignalPin = sSigPin;
}

int sensor::readVoltage() {
	// Read the sensor's voltage and return it
	sensorVoltage = analogRead(sensorSignalPin);
	return sensorVoltage;
}
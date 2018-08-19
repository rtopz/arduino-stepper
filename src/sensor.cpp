#include <Arduino.h>
#include "sensor.h"

sensor::sensor(int sSigPin, bool sTypeOpen) {
	sensorSignalPin = sSigPin;

	if(sTypeOpen ==  true) {
		sensorTypeOpen = true;
	}
	else {
		sensorTypeOpen = false;
	}
}

bool sensor::readSensor() {
	// Read the sensor's voltage and return it
	sensorVoltage = analogRead(sensorSignalPin);

	// Sensor voltage comparison should be checked vs sensor pulling up High (3.3V or 5V) or Low (0V)
	if(sensorTypeOpen) {
		// Above 400/1024 * 5V or 3.3V for Open sensors
		if(sensorVoltage > 400) {
			return false;	// End stop not hit
		}
		else {
			return true;
		}
	}
	else {
		// 0V for Closed sensors
		if(sensorVoltage < 50) {
			return false;
		}
		else{
			return true;
		}
	}
}
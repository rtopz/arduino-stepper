#ifndef sensor_H
#define sensor_H
#include <Arduino.h>

class sensor {
	private:
		int sensorSignalPin;
		int sensorVoltage;

	public:
		sensor(int sSigPin);
		int readVoltage();
};

#endif
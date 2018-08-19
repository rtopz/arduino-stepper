#ifndef sensor_H
#define sensor_H
#include <Arduino.h>

class sensor {
	private:
		int sensorSignalPin;
		bool sensorVoltage;
		bool sensorTypeOpen;

	public:
		sensor(int sSigPin, bool sTypeOpen);
		bool readSensor();
		bool getSensorType();
};

#endif
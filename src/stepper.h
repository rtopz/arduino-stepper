#ifndef stepper_H
#define stepper_H
#include <Arduino.h>
#include "sensor.h"

class stepper {
	private:
		int motorDirectionPin;
		int motorStepPin;
		int stepsPerRevolution;

	public:
		stepper(int mDirPin, int mStepPin, int stepsPerRev);
		void runSensorHoming(sensor * sensorObj);
		void moveNumSteps(int steps);
		void moveBeltDistance(int distance, double beltPitch);
};

#endif
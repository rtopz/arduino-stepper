#ifndef stepper_H
#define stepper_H
#include <Arduino.h>

class stepper{
	private:
		int motorDirectionPin;
		int motorStepPin;
		int sensorSignalPin;
		int stepsPerRevolution;

	public:
		stepper(int mDirPin, int mStepPin, int sSigPin, int stepsPerRev);
		void runHoming();
		void moveNumSteps(int steps);
		void moveBeltDistance(int distance, double beltPitch);
};

#endif
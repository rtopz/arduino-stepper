#ifndef stepper_H
#define stepper_H
#include <Arduino.h>

class stepper{
	private:
		int motorDirectionPin;
		int motorStepPin;
		int sensorSignalPin;

	public:
		stepper(int motorDirectionPin, int motorStepPin, int sensorSignalPin);
		void runHoming();
};

#endif
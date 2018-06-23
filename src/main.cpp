#include <Arduino.h>
#include "stepper.h"

#define		stepsPerRev			200		// Sets the motor's steps per 1 revolution (360deg)
#define		stepRangeMax		1000
#define		distanceRangeMax	200
#define		motorDirPin			2
#define		motorStepPin		3
#define		sensorSigPin		1

stepper * motor1;
int count;

void setup() {
	Serial.begin(9600);

	Serial.println("Initialize stepper motor 1");
	motor1 = new stepper(motorDirPin, motorStepPin, sensorSigPin, stepsPerRev);
	Serial.println("Homing motor 1");
	motor1->runHoming();
}

void loop() {
}
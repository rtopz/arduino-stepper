#include <Arduino.h>
#include "stepper.h"

// Define details about motor #1
#define		m1_stepsPerRev			200		// Sets the motor's steps per 1 revolution (360deg)
#define		m1_stepRangeMax		1000
#define		m1_distanceRangeMax	200
#define		m1_dirPin		2
#define		m1_stepPin		3
#define		s1_sigPin		1

stepper * motor1;
int count;

void setup() {
	Serial.begin(9600);

	Serial.println("Initialize stepper motor 1");
	motor1 = new stepper(m1_dirPin, m1_stepPin, s1_sigPin, m1_stepsPerRev);
	Serial.println("Homing motor 1");
	motor1->runSensorHoming();
}

void loop() {
}
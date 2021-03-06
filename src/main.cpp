#include <Arduino.h>
#include "stepper.h"
#include "sensor.h"

// Define details about motor #1
#define		m1_stepsPerRev		200		// Sets the motor's steps per 1 revolution (360deg)
#define		m1_stepRangeMax		1000
#define		m1_distanceRangeMax	200
#define		m1_dirPin		2
#define		m1_stepPin		3
#define		s1_sigPin		1

stepper * motor1;
sensor * sensor1;
int count;

void setup() {
	Serial.begin(9600);

	Serial.println(F("Initialize stepper motor 1"));
	motor1 = new stepper(m1_dirPin, m1_stepPin, m1_stepsPerRev);

	Serial.println(F("Initialize sensor 1 as type = Normally Open"));
	sensor1 = new sensor(s1_sigPin, true);

	Serial.println(F("Homing motor 1"));
	motor1->runSensorHoming(sensor1);
}

void loop() {
}
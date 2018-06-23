#include <Arduino.h>
#include "stepper.h"

stepper::stepper(int mDirPin, int mStepPin, int sSigPin, int stepsPerRev) {
	motorDirectionPin = mDirPin;
	motorStepPin = mStepPin;
	sensorSignalPin = sSigPin;
	stepsPerRevolution = stepsPerRev;

	// Set to OUTPUT mode for the Arduino digital pins
	pinMode(motorDirectionPin, OUTPUT);
	pinMode(motorStepPin, OUTPUT);
}

// Runs a home of the stepper 
void stepper::runHoming() {
	bool loop = true;	// Used to break out of infinite loop
	int sensorVoltage = 0;

	// Set the rotation direction for the initial homing
	// HIGH =  & LOW =
	digitalWrite(motorDirectionPin, HIGH);

	while(loop) {
		sensorVoltage = analogRead(sensorSignalPin);	// Read the sensor before moving a step
		if(sensorVoltage < 400) {
			digitalWrite(motorStepPin, HIGH);			// Set step pin to high to rotate
			delay(2);									// Delay added to not immediately stop when switching to low voltage
			digitalWrite(motorStepPin, LOW);			// Set step pin to low to pause rotate
			delay(3);									// Delay added to slow down rotation speed a bit
			Serial.print(".");
		}
		else {
			// Reverse the motor direction to prevent crashing into sensor
			if(digitalRead(motorDirectionPin) == HIGH) {
				digitalWrite(motorDirectionPin, LOW);
			}
			else {
				digitalWrite(motorDirectionPin, HIGH);
			}

			loop = false;	// Get out of loop
		}
	}
}

void stepper::moveNumSteps(int steps) {
}
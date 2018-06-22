#include "stepper.h"

stepper::stepper(int mDirPin, int mStepPin, int sSigPin) {
	motorDirectionPin = mDirPin;
	motorStepPin = mStepPin;
	sensorSignalPin = sSigPin;
}

// Runs a home of the
void stepper::runHoming() {
	bool loop = true;	// Used to break out of infinite loop
	int opticalVoltage = 0;

	// Set the rotation direction for the initial homing
	// HIGH =  & LOW =
	digitalWrite(motorDirectionPin, HIGH);

	while(loop) {
		opticalVoltage = analogRead(sensorSignalPin);	// Read the optical sensor before moving a step
		if(opticalVoltage < 400) {
			digitalWrite(motorStepPin, HIGH);			// Set step pin to high to rotate
			delay(2);									// Delay added to not immediately stop with low voltage
			digitalWrite(motorStepPin, LOW);			// Set step pin to low to pause rotate
			delay(3);									// Delay added to slow down rotation speed
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
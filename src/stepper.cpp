#include <Arduino.h>
#include "stepper.h"
#include "sensor.h"

stepper::stepper(int iMDirPin, int iMStepPin, int iStepsPerRev) {
	motorDirectionPin = iMDirPin;
	motorStepPin = iMStepPin;
	stepsPerRevolution = iStepsPerRev;

	// Set to OUTPUT mode for the Arduino digital pins
	pinMode(motorDirectionPin, OUTPUT);
	pinMode(motorStepPin, OUTPUT);
}

// Runs a home of the stepper using the reference to a sensor object.  Sensor object should be initialized
//  before running a home.
void stepper::runSensorHoming(sensor * sensorObj) {
	bool bLoop = true;	// Used to break out of infinite loop
	bool endstopHit = false;

	// Set the rotation direction for the initial homing
	// HIGH =  & LOW =
	digitalWrite(motorDirectionPin, HIGH);

	while(bLoop) {
		endstopHit = sensorObj->readSensor();	// Read the sensor before moving a step
		
		// Check sensor to see if it was triggered
		if(!endstopHit) {
			digitalWrite(motorStepPin, HIGH);		// Set step pin to high to rotate
			delay(2);								// Delay added to not immediately stop when switching to low voltage
			digitalWrite(motorStepPin, LOW);		// Set step pin to low to pause rotate
			delay(3);								// Delay added to slow down rotation speed a bit
			Serial.print(".");
		}
		else {
			Serial.println("");
			Serial.println(F("Endstop hit, reversing motor direction"));
			// Reverse the motor direction to prevent crashing into sensor
			if(digitalRead(motorDirectionPin) == HIGH) {
				digitalWrite(motorDirectionPin, LOW);
			}
			else {
				digitalWrite(motorDirectionPin, HIGH);
			}

			bLoop = false;	// Get out of loop
		}
	}
}

void stepper::moveNumSteps(int steps) {
	Serial.print((String)"" + F("Moving motor ") + (String)steps + F(" steps"));
	for (int x=0; x < steps; x++) {
		digitalWrite(motorStepPin, HIGH);		// Set step pin to high to rotate
		delay(2);								// Delay added to not immediately stop when switching to low voltage
		digitalWrite(motorStepPin, LOW);		// Set step pin to low to pause rotate
		delay(3);	
		Serial.print(".");
	}
	Serial.println("Done");
}
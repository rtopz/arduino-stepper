#include <Arduino.h>

#define		stepsPerRevolution	200		// Sets the motor's steps per 1 revolution (360deg)
#define		stepRangeMax		1000
#define		motorDirPin			2
#define		motorStepPin		3
#define		sensorSignalPin		1

// Declare any used functions here
void runHoming();

int count;

void setup() {
	Serial.begin(9600);

  Serial.println("Setup motor to steps: " + (String)stepsPerRevolution);
  pinMode(motorDirPin, OUTPUT);		// Direction pin for A4988
  pinMode(motorStepPin, OUTPUT);	// Step pin for A4988
  
  Serial.println("Starting Initial Homing");
  runHoming();
  Serial.println("\nHomed to Starting Position");

  count = 1;
}

void loop() {
}

// Runs a home of the
void runHoming() {
	bool loop = true;	// Used to break out of infinite loop
	int opticalVoltage = 0;

	// Set the rotation direction for the initial homing
	// HIGH =  & LOW =
	digitalWrite(motorDirPin, HIGH);

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
			if(digitalRead(motorDirPin) == HIGH) {
				digitalWrite(motorDirPin, LOW);
			}
			else {
				digitalWrite(motorDirPin, HIGH);
			}

			loop = false;	// Get out of loop
		}
	}
}

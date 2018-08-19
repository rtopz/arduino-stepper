# arduino-stepper

## Version:
0.0.4

## Summary:
Program contains libraries for helping arduino run a stepper motor using the A4988 steper driver with a sensor

## To Do:
* Add move steps function
* Add distance move (via belt) function
* Configure stepper micro-stepping

## Changes:
### v0.0.4
 * Configure sensor open/close capability for sensors that can be closed (0V) or open (V+) when triggered
### v0.0.3
 * Separated out sensor object from stepper
 * Stepper homing using a sensor will take a pointer reference to an initialized sensor object
### v0.0.2
 * Separated out functions to different class
 * Create motor/stepper objects
 * Removed reference to optical sensors
### v0.0.1
 * Base release with no classes
 * Functional test to home stepper motor using optical sensor
// MultiStepper
// -*- mode: C++ -*-
//
// Control both Stepper motors at the same time with different speeds
// and accelerations. 
// Requires the AFMotor library (https://github.com/adafruit/Adafruit-Motor-Shield-library)
// And AccelStepper with AFMotor support (https://github.com/adafruit/AccelStepper)
// Public domain!
// Don't forget AccelStepper.h in the libraries

#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(48, 1);
AF_Stepper motor2(96, 2);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, SINGLE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup()
{  
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(100.0);
    // stepper1.moveTo(240);
    
    stepper2.setMaxSpeed(300.0);
   stepper2.setAcceleration(100.0);
   // stepper2.moveTo(1000);
 
    
}

void loop()
{
   
    stepper1.runToNewPosition(0);
    stepper1.runToNewPosition(500);
    stepper1.runToNewPosition(100);
    stepper1.runToNewPosition(120);
    stepper1.run();
    delay(2000);
    
    stepper2.runToNewPosition(0);
    stepper2.runToNewPosition(500);
    stepper2.runToNewPosition(100);
    stepper2.runToNewPosition(120);
    stepper2.run();
}

#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
// Use arduino UNO
AF_Stepper motor1(48, 1);
AF_Stepper motor2(96, 2);

char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

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

void setup() {
    Serial.begin(9600);
    Serial.write("Power On");
    pinMode(13, OUTPUT); //LED TEST
    
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(100.0);
    // stepper1.moveTo(240);
    
   stepper2.setMaxSpeed(300.0);
   stepper2.setAcceleration(100.0);
}

String Comp() {
  
   String aString;
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 19) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    delay(5);
    }  
    index=0;
    aString=inData;
return(aString);
}

void loop()
{
  String axes;
  String myString;
  myString=Comp();
  String myValue;
  myValue=myString.substring(1); //OK with a delay in reading loop read from char 1 to the end
  axes=myString.substring(0,1);
  int myIntValue;
  char myCharValue[myValue.length()+1];
  int myValueLength=myValue.length()+1; //length() +1 for the right size
  myValue.toCharArray(myCharValue,myValueLength);
  myIntValue=atoi(myCharValue);
  Serial.println(myCharValue);
  if (axes="x")
  {
    stepper1.runToNewPosition(myIntValue);
    stepper1.run();

        digitalWrite(13, HIGH);
        delay(5);
        Serial.println("ok");
        delay(5);

        //Serial.write("Motor 1 -> Offline\n");

    }
    else {
      Serial.println("nok");
      digitalWrite(13, LOW);  
    }
 
  
}


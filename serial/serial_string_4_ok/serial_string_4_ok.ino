char inData[20]; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character

void setup() {
    Serial.begin(9600);
    Serial.write("Power On");
    pinMode(13, OUTPUT); 
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
    }  
    index=0;
    aString=inData;
return(aString);
}

void loop()
{
  String aString;
  aString=Comp();
  
    if (aString=="m") {
        Serial.write("Motor 1 -> Online\n");
        digitalWrite(13, HIGH);
    }
    if (aString=="p") {
        Serial.write("Motor 1 -> Offline\n");
        digitalWrite(13, LOW);  
    }
}


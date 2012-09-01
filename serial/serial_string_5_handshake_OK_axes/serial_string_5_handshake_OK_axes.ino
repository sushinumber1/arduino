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
    if (myIntValue==1000) {
     // if (Comp()=="m") {
        //Serial.write("Motor 1 -> Online\n");
        digitalWrite(13, HIGH);
        delay(5);
        Serial.println("ok");
        delay(5);
    }
    else if (myIntValue==2000) {
//    if (Comp()=="p") {
        //Serial.write("Motor 1 -> Offline\n");
        digitalWrite(13, LOW);  
        delay(5);
        Serial.println("ok");
        delay(5);
    }
    else {
      Serial.println("nok");
    }
  }
    else {
      Serial.println("NOT AN AXE");
    }
}


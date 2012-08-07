/* Stepper Copal
 * -------------
 *
 * Program to drive a stepper motor coming from a 5'25 disk drive
 * according to the documentation I found, this stepper: "[...] motor 
 * made by Copal Electronics, with 1.8 degrees per step and 96 ohms 
 * per winding, with center taps brought out to separate leads [...]"
 * [http://www.cs.uiowa.edu/~jones/step/example.html]
 *
 * It is a unipolar stepper motor with 5 wires:
 * 
 * - red: power connector, I have it at 5V and works fine
 * - orange and black: coil 1
 * - brown and yellow: coil 2
 *
 * (cleft) 2005 DojoDave for K3
 * http://www.0j0.org | http://arduino.berlios.de
 *
 * @author: David Cuartielles
 * @date: 20 Oct. 2005
 */
int motor0Pin1 = 3;
int motor0Pin2 = 2;
int motor0Pin3 = 12;
int motor0Pin4 = 13;
int motor1Pin1 = 4;
int motor1Pin2 = 5;
int motor1Pin3 = 6;
int motor1Pin4 = 7;
int delayTime = 10;
int incomingByte=0;
//int init;

void setup() {
  pinMode(motor0Pin1, OUTPUT);
  pinMode(motor0Pin2, OUTPUT);
  pinMode(motor0Pin3, OUTPUT);
  pinMode(motor0Pin4, OUTPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor1Pin3, OUTPUT);
  pinMode(motor1Pin4, OUTPUT);
  Serial.begin(9600);
//  init=4;
}
int foo =4; //motor phase init outside the loop for initialisation

void loop() {
int stop_phase;

if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();
		// say what you got:
		//Serial.print("I received: ");
		Serial.println(incomingByte, DEC);
if (incomingByte==1) m0phase1();
if (incomingByte==2) m0phase2();
if (incomingByte==3) m0phase3();
if (incomingByte==4) m0phase4();
if (incomingByte==5) m1phase1();
if (incomingByte==6) m1phase2();
if (incomingByte==7) m1phase3();
if (incomingByte==8) m1phase4();
}

}

void m0phase1()
{
  digitalWrite(motor0Pin1, HIGH);
  digitalWrite(motor0Pin2, LOW);
  digitalWrite(motor0Pin3, LOW);
  digitalWrite(motor0Pin4, LOW);
  delay(delayTime);
}
void m0phase2()
{
  digitalWrite(motor0Pin1, LOW);
  digitalWrite(motor0Pin2, HIGH);
  digitalWrite(motor0Pin3, LOW);
  digitalWrite(motor0Pin4, LOW);
  delay(delayTime);
}
void m0phase3()
{
  digitalWrite(motor0Pin1, LOW);
  digitalWrite(motor0Pin2, LOW);
  digitalWrite(motor0Pin3, HIGH);
  digitalWrite(motor0Pin4, LOW);
  delay(delayTime);
}
void m0phase4()
{
  digitalWrite(motor0Pin1, LOW);
  digitalWrite(motor0Pin2, LOW);
  digitalWrite(motor0Pin3, LOW);
  digitalWrite(motor0Pin4, HIGH);
  delay(delayTime);
}

void m1phase1()
{
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
}
void m1phase2()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
}
void m1phase3()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, HIGH);
  digitalWrite(motor1Pin4, LOW);
  delay(delayTime);
}
void m1phase4()
{
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor1Pin3, LOW);
  digitalWrite(motor1Pin4, HIGH);
  delay(delayTime);
}

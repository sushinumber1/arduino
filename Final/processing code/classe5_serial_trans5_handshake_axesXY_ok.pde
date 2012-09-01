import processing.serial.*;
Serial myPort; // The serial port

ArrayList element = new ArrayList();
String lines[];
int i=0; //index
int j=0; //index


void setup()
{
println(Serial.list());
String portName = Serial.list()[0];
myPort = new Serial(this, portName, 9600);

lines= loadStrings("coord.txt");

}

void draw()
{
  if (i < lines.length) {
         float values[] = float(lines[i].split(":")[1].split( ","));
         element.add( new Element( values[0], values[1]));
         i++;
   }
   else
   {
     if (j < lines.length) {
         Element coord= (Element) element.get(j); 
         coord.disp();
         coord.writeX();
         coord.readSerial();
         delay(50);
         coord.writeY();
         coord.readSerial();
         delay(5000);
         j++;
     }
     else
     {
     println("END");
     }
    
   // Element coord= (Element) element.get(1); 
    //coord.disp();
    //delay(5000);
    //coord.test();
   }


}

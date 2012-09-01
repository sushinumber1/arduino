class Element {
        float x,y;
        String myString2;
        int which;

        Element(float x, float y) {
                this.x = x;
                this.y = y;
                println("--x:"+x+"--y;"+y);
        }
    void disp()
    {
     println( "--dis");
     println("--x:"+x+"--y;"+y);
     //delay(500000);
    }
    void test()
    {
      int a;
      a=int(x);
      println(a);
    }
    void writeX()
    {      
      int a;
      a=int(x);
      String b=String.valueOf(a);
      String c="x"+b;
      myPort.write(c);
      delay(200);
      println("#### x :"+c +" wrtten to the serial port");
    }
    
    void writeY()
    {      
      int a;
      a=int(x);
      String b=String.valueOf(a);
      String c="y"+b;
      myPort.write(c);
      delay(200);
      println("#### x :"+c +" wrtten to the serial port");
    }
    void readSerial()
    {
      while (myString2 =="nok") 
      {
       while (myPort.available() > 0) {
         String inBuffer = myPort.readStringUntil('\n');   
         if (inBuffer != null) {
           String myString = new String(inBuffer); 
           myString2 = trim(myString);
           //------------------
           //---------------------  
            // println("EPIC"); 
            println("FAIL"); 
          }
        }
      }
         //----------------------------------   
       // if (myString2.equals("ok"))  which=1; 
       // if (myString2.equals("nok"))  which=2; 
	    println("Good"); 
            println("transmission clear");
            delay(50);

       //------------------------------------   
    }
    

}


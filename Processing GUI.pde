/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int x,y=0;      // Data received from the serial port
String s;
void setup() 
{
  size(400,400);
  String portName = Serial.list()[0];
  println(Serial.list()[0]);
  myPort = new Serial(this, portName, 9600);
  textSize(10);
}
void draw(){
  if(key>='0'&&key<='9'){
    myPort.write(key);
    println(key);
  }
  kick();
}
void kick(){
  if(s!=null&&s.length()>0){
    String[] leist = split(s, ',');
    for(int i = 0 ; i < 6 ; i+=2){
      if(leist[i].length()>0)
      y=Integer.parseInt(leist[i]);
      if(leist[i+1].length()>0)
      x=Integer.parseInt(leist[i+1]);
      println(s);
      rect(20*y,20*x,20,20);
      text(y+","+x,20*y,20*x);
    }
  }
}
void serialEvent(Serial myPort){
  try{
    s=myPort.readStringUntil('\n'); 
  }
  catch (Exception e){
  }  
}
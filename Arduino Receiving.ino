#include <SoftwareSerial.h>
SoftwareSerial BTserial(11, 12); // RX | TX
// Connect the HC-05 TX to Arduino pin 11 RX. 
// Connect the HC-05 RX to Arduino pin 12 TX through a voltage divider. 
char c = " ";
int d = 0;
int serial=0;
int counter=2;
int count=0;
void setup() 
{
  Serial.begin(9600);  
  // HC-05 default serial speed for AT mode is 38400
  BTserial.begin(38400);
  BTserial.flush();
}
 
void loop()
{
  if(counter==2)
  {
    if(Serial.available())
    {
      serial=Serial.parseInt();
      BTserial.write(serial);
      counter=1;
    }
  }
  for(int i = 0 ; i < 6 ; i++){
    if(BTserial.available()){
    c = BTserial.read();
    BTserial.write(" ");
    d = (int)c;
    Serial.print(d);
    Serial.print(",");
    count++;
    }
  }
  if(count==6)
  {
    Serial.println();
    count=0;
  }
}
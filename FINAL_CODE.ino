#include<SoftwareSerial.h>
//Library for Sonar
#include<NewPing.h>
#include<Servo.h>
#include<Stepper.h>
//Connect Ping Pin to Arduino Pin A1
//Connect Echo Pin to Arduino Pin A0
#define pingPin  A1
#define echoPin  A0
//Max Distance A Sonar can Measure
#define Max 400
SoftwareSerial BTserial(3, 4); // RX | TX
// Connect the HC-05 TX to Arduino pin 3 RX. 
// Connect the HC-05 RX to Arduino pin 4 TX.
Servo myservo;
//steps = Number of steps a stepper motor takes in a revolution
const int steps = 200;
int dir=1;//1=along positive x axis,,2=along positive y axis;
//Size of the floor
int c[18][18] = {0};
// x and y are coordinates of the Bot at any moment
int x=1, y=1,kx=0,ky=0;
//a is an array that will contain the distances in three directions
int a[3] = {0};
NewPing sonar(pingPin , echoPin , Max);
Stepper Stepperleft(steps , 13 ,12,11,10);
Stepper Stepperright(steps , 6,7,8,9);
bool not_start=true;
void setup()
{
  myservo.attach(5);
  myservo.write(86);
  Serial.begin(9600);
  //Baud rate for Bluetooth
  BTserial.begin(38400);
  BTserial.flush();
}

void loop() 
{
  while(not_start)
  {
    if(BTserial.available())
    {
      not_start=false;
    }
  }
  fun();
} 
void fun(){
  for (int pos=0, s =2; pos <= 180;s--, pos += 86){
    setposition(pos);
    delay(100);
    //collecting distance in three directions.
    int distance = sonar.ping_cm();
    //22 is the matrix size that we took.
    a[s] = distance/22;
    delay(500);
   } 
  setposition(86);
  //Allocating the coordinates of objects.
  if(dir==1){
    for(int i=0;i<3;i++)
    {      
      if(i==1){
	      kx=x+a[i]+1;
        while(!BTserial.available()){
        }
        BTserial.write(char(kx));
        delay(50);
        while(!BTserial.available()){    
        }
        BTserial.write(char(y));
        delay(50);
      }
      if(i==0){ 
        ky=y-a[i]-1; c[x][ky]=1;
        while(!BTserial.available()){
              
        }
        BTserial.write(char(x));
        delay(50);
        while(!BTserial.available()){
            
        }
        BTserial.write(char(ky));
        delay(50);
      }
      if(i==2){
        ky=y+a[i]+1;  c[x][ky]=1;
        while(!BTserial.available()){
              
        }
        BTserial.write(char(x));
        delay(50);
        while(!BTserial.available()){
        }
        BTserial.write(char(ky));
        delay(50);
      }
    }
  }
  else if(dir==2){
    for(int i=0;i<3;i++){    
      if(i==1){
        ky=y+a[i]+1;
        while(!BTserial.available()){
        }
        BTserial.write(char(x));
        delay(50);
        while(!BTserial.available()){
        }
        BTserial.write(char(ky));
        delay(50);
      }
      if(i==2){
        kx=x-a[i]-1;
        while(!BTserial.available()){
        }
        BTserial.write(char(kx));
        delay(50);
        while(!BTserial.available()){
              
        }
        BTserial.write(char(y));
        delay(50);
      }
      if(i==0){
        kx=x+a[i]+1;
        while(!BTserial.available()){
        }
        BTserial.write(char(kx));
        delay(50);
        while(!BTserial.available()){
              
        }
        BTserial.write(char(y));
        delay(50);
      }
    }
  }
  else if(dir==3){   
    for(int i=0;i<3;i++){   
      if(i==1){
        kx=x-a[i]-1;
        while(!BTserial.available()){
              
        }
        BTserial.write(char(kx));
        delay(50);
        while(!BTserial.available()){
              
        }
        BTserial.write(char(y));
        delay(50);
      }
      if(i==2){
        ky=y-a[i]-1;
        while(!BTserial.available()){
              
        }
        BTserial.write(char(x));
        delay(50);
        while(!BTserial.available()){
            
        }
        BTserial.write(char(ky));
        delay(50);
      }        
      if(i==0){
        ky=y+a[i]+1;
        while(!BTserial.available()){
              
        }
        BTserial.write(char(x));
        delay(50);
        while(!BTserial.available()){
            
        }
        BTserial.write(char(ky));
        delay(50);
      }
    }
  }
  else{       
    for(int i=0;i<3;i++){
      if(i==1){
        ky=y-a[i]-1; c[x][ky]=1;
        while(!BTserial.available()){
        }
        BTserial.write(char(x));
        delay(50);
        while(!BTserial.available()){
        }
        BTserial.write(char(ky));
        delay(50);
      }
      if(i==2){
        kx=x+a[i]+1; c[kx][y]=1;
        while(!BTserial.available()){
              
        }
        BTserial.write(char(kx));
        delay(50);
        while(!BTserial.available()){
              
        }
        BTserial.write(char(y));
        delay(50);
      }
      if(i==0){
        kx=x-a[i]-1;  c[kx][y]=1;
        while(!BTserial.available()){
        }
        BTserial.write(char(kx));
        delay(50);
        while(!BTserial.available()){
              
        }
        BTserial.write(char(y));
        delay(50);
      }
    }
  }
  //If there is object in front then changing the direction
  if(a[1]<1) dir=directionchange(a,3,dir);
  while(!BTserial.available()){          
  }
  delay(50);
  forward(); 
  if(dir==1) x++;
  else if(dir==2) y++;
  else if(dir==3) x--;
  else y--;
 }

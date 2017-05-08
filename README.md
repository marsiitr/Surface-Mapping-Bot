# Surface-Mapping-Bot
##### Project done in Shristi 2017

### Abstract
Surface-Mapping-Bot is an autonomous bot which maps the whole surface after all around the area. It detects any objects and walls that are around it and then it sends their cooardinates to the PC via bluetooth which displays its map on the screen. Ultrasonic sensor is used for the detection of the objects and "Processing" software is used for displaying the map.

### Team Members
1. Rahul
2. Aniket gajare
3. Rohit Jethani

### Mentors
1. Bhaskar Kaushik
2. Gotham Sairam
3. Aayushi Srivastava

### Pre-requisites
**Software: ** 
 * Arduino
 * Processing
**Hardware: ** 
 * HC-SR04(Ultrasinic Sensor): For the detection of objects.
 * Servo Motor
 * Stepper Motors(2): Stepper because we want the bot to cover exact specific distance at a time. We can use DC motor with                           ENCODER also.
 * HC-05(Bluetooth Modules): For the wireless Serial Communication.
 * Arduino(2): We used arduino UNO both sides. You can use any type of arduino according to mechanics.
 
### How to run the Setup
Firstly put the dimensions of the field in the code, upload it and then switch on the bot at the corner of the field then after proper pairing of the bluetooths, press any key on the keyboard. Servo will start moving and the ultrasonic sensor mounted on it will record the coordinates of the objects and the data will be sent to PC where it will be interpreted to give the required map.

### Applications
* It can be sent to the places where human access is not possible where it can send the map of the place and further plan accordingly.
* Mine detection robot is based on wireless networks. It can be made using microcontroller for a remote controlled mine detecting robot using sensors.when any obstacles comes in front of the robot,IR or metal sensors senses that obstacle and send appropriate signal to the microcontroller.
* It can be used at homes so that it will map the whole house and then we can program it do many activities like autonomous vaccum cleaning of house, Serving food to the guests etc.

### Design
A rectangular cardboard of around 18 * 15 is used and the servo is mounted on the front side on which the ultrasonic sensor is placed. Two Stepper motors are placed under the cardboard and mounted by L-mount on the front side of the bot. A castor wheel is used on the back side for easy navigation. Whole electronics part is placed above the bot with arduino, breadboard and battery.

### Future Scope
* We can improve its algorithm to map the whole area so that it will not leave any place.
* Right now it is only calculating the distances in three directions, we can enhance it to see in all directions at 360 range.



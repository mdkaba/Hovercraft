#include <Servo.h>
#include "SharpIR.h"
Pin Set Up
++++++++++++++++++++++++++++++++++++++++++++++++++++
//fans
int lift = 7; //PD7 (ON/Off 0) can change pin if need
int thrust = 6; //PB2 (PWM2) UP/Down power
//fan speed
int thrust_speed;
int start_speed;
int minimum = 0; //lowest speed of fan
int maximum = 255; //highest speed of fan
// May need to had inital fan speed for thrust
//___________________________________________________________________________________
//servo
Servo myservo;
int pos = 88; //the starting position of motor (may not need this)
//_________________________________________________________________________________
//sensor
// D4 = PIN 5
// D5 = PIN 12
//IR Sensor
SharpIR SharpIR1(PC3, 1080); //RIGHT
SharpIR SharpIR2(PC4, 1080); // LEFT
int dis; // RIGHT
int dis1; // LEFT
//___________________________________________________________________________
47
//turning
bool turn = true;
//int turn_count = 0;
//start main program
bool On = true;
//++++++++++++++++++++++++++++++ Void Set up
+++++++++++++++++++++++++++++++++++++++++++++++++++++
//run once:
void setup() {
Wire.begin(); //TWBR = 12; //400 kbit/sec I2C speed
Serial.begin(9600); //display speed in serial monitor can change
//while (!Serial) {};
//Servo set up
myservo.attach(9); // servo attched on pin 9 (PB1 -> PWM0)
myservo.write(pos);
delay(15); //to allow time for servo to reach position
// Set up the interrupt pin, its set as active high, push-pull
pinMode(intPin, INPUT);
digitalWrite(intPin, LOW);
pinMode(myLed, OUTPUT);
digitalWrite(myLed, HIGH);
// set up interrupt pin for sensors
pinMode(5,OUTPUT);
pinMode(12,OUTPUT);
pinMode(PC3, OUTPUT);
pinMode(PC4, OUTPUT);
analogReference(DEFAULT);
//the default analog reference of 5 volts (on 5V Arduino boards) or
//3.3 volts (on 3.3V Arduino boards)
// set up interrupt pin for fans
pinMode(thrust, OUTPUT);
analogWrite(thrust, 255);
48
pinMode(lift, OUTPUT);
digitalWrite(lift, LOW);
}
//===============================================================================
====================
//+++++++++++++++++++++++++++++++++ Void Loop
+++++++++++++++++++++++++++++++++++++++++++++++++
//run repeatedly
void loop() {
//just add function order and small details
if (On){
start();
}
else{
_end();
}
//check distance
read_IR();
if(dis > 40){
turn_right();
}
else if(dis1 > 40)
{
turn_left();
}
}
//++++++++++++++++++++++++++++++ Functions ++++++++++++++++++++++++++++++++++++++++
//============================= Fan =========================================
//Lift on
void turnOn(){
digitalWrite(lift, HIGH);
}
49
//Lif off
void turnoff(){
digitalWrite(lift,LOW);
}
//thrust off (may not need this
void thrustoff(){
analogWrite(thrust,0);
}
//max and min values of the thrust fan
void maximum_minimum(){
if (thrust_speed > maximum){
thrust_speed = maximum;
}
else if (thrust_speed < minimum) {
thrust_speed = minimum;
}
}
//___________________________Hover craft on/off, moving ____________________
//Turning off hover craft (END) both lif and thrust fan are off
void _end(){
turnoff();
thrustoff();
myservo.write(90); //changes the servo angle to be to 90 again
}
//starting of hover craft (starr)
void start(){
turnOn();
thrust_speed = 255; //change the starting speed
forward();
}
//moving forward in straight line
void forward(){
analogWrite(thrust, thrust_speed); //can adjust speed if needed
}
50
//______________________________Sensor and servo section____________________________________
//Sensors
void read_IR()
{
dis=SharpIR1.distance(); // this returns the distance to the object you're measuring
dis1=SharpIR2.distance();
Serial.print("Dis: ");
Serial.print(dis);
Serial.print("Dis1: ");
Serial.print(dis1);
}
//__________________________Turning of hovercraft_________________________________
void turn_left(){
analogWrite(6,240);
myservo.write(55);
delay (1500);
myservo.write(35);
delay(1000);
myservo.write(88);
}
void turn_right(){
analogWrite(6,240);
myservo.write(105);
delay (1500); //can change wait time to be slower or faster
myservo.write(155);
delay(1500);
myservo.write(70);
delay(500);
myservo.write(88);
}
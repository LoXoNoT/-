//Функции для поворотов/вперед
#include <Servo.h>
Servo serZ; 
Servo serP; 
int x=0;
int y=0;
int a=0;
int b=0;
int pogrz=0;
int razgr=0;
const int servoPort = 2; 
const int servoPort1 = 5;  
const int port_M1_6 = 6; //левый мотор 
const int port_M1_7=7;
const int port_M2_45=45; //правый мотор
const int port_M2_46=46;
const int m = A9;
const int r = A8;
const int l= A10;
int r1 = 0;
int m1 = 0;
int l1 = 0;
int ooo=0;
void setup() {
  pinMode(port_M1_6, OUTPUT);
  pinMode(port_M1_7, OUTPUT);
  pinMode(port_M2_45, OUTPUT);
  pinMode(port_M2_46, OUTPUT);
  pinMode(r, INPUT);
  pinMode(l, INPUT);
  pinMode(m, INPUT);
  serP.attach(servoPort); 
  serZ.attach(servoPort1); 
  Serial.begin(9600);
  r1 = analogRead(r);
  l1 = analogRead(l);
  m1 = analogRead(m);
}
void d(int t)
{
 
   digitalWrite(port_M1_6, 1);
  digitalWrite(port_M1_7, 0);
  digitalWrite(port_M2_45, 1);
  digitalWrite(port_M2_46, 0);
  delay(t);
 
}
void Z(int t)
{
 
   digitalWrite(port_M1_6, 0);
  digitalWrite(port_M1_7, 1);
  digitalWrite(port_M2_45, 0);
  digitalWrite(port_M2_46, 1);
  delay(t);
 
}
void pogr ()
{
a=0;
b=0;

   if (l1>400||r1>400)
  {
    stop();
    if (x!=1){
        serZ.writeMicroseconds(1200);
        delay(400);
        serZ.writeMicroseconds(1500);
        x=x+1;} 
        delay(200);
  if (y!=1){
    serP.writeMicroseconds(1200);
    delay(500);
    serP.writeMicroseconds(1500);
    y=y+1;
    right(17600);
stop();
 pogrz++;
 razgr=0;}




  }
  
 
 }
void raz ()
{
x=0;
y=0;
   if (l1>400&&r1>400)
  {
    stop();
    if (a!=1){
        serP.writeMicroseconds(1700);
        delay(500);
        serP.writeMicroseconds(1500);
        a=a+1;} 
        delay(200);
        
  if (b!=1){
    serZ.writeMicroseconds(1700);
    delay(600);
    serZ.writeMicroseconds(1500);
    b=b+1;
    Z(5000);
    right(17600);
stop();
 pogrz=0;
 razgr++;

 }




  }
  
 
 }

void w()
{
 
   digitalWrite(port_M1_6, 1);
  digitalWrite(port_M1_7, 0);
  digitalWrite(port_M2_45, 1);
  digitalWrite(port_M2_46, 0);

  
 
}
void left()
{
 
   digitalWrite(port_M1_6, 1);
  digitalWrite(port_M1_7, 0);
  digitalWrite(port_M2_45, 0);
  digitalWrite(port_M2_46, 1);
 
}
void right(int t)
{
 
   digitalWrite(port_M1_6, 0);
  digitalWrite(port_M1_7, 1);
  digitalWrite(port_M2_45, 1);
  digitalWrite(port_M2_46, 0);
  delay(t);
 
}
void stop()
{
  digitalWrite(port_M1_6, 0);
  digitalWrite(port_M1_7, 0);
  digitalWrite(port_M2_45, 0);
  digitalWrite(port_M2_46, 0);
  
}

void loop() {
    m1=analogRead(m);
  r1=analogRead(r);
  l1=analogRead(l); 
 w();
 if (pogrz==0){
 pogr();}
 w();
 if (razgr==0){
 raz();}

 
}

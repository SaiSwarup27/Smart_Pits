#include <Servo.h>
int servoPinr=7;
int servoPini=6;
Servo Servor;
//Servo Servoi;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT); //IR
  pinMode(12,INPUT); //Rainfall
  pinMode(11,OUTPUT); //Green LED
  pinMode(10,OUTPUT); //Red LED
  pinMode(9,OUTPUT); //Blue LED
  pinMode(4,OUTPUT); //Buzzer
  Servor.attach(servoPinr);
  //Servoi.attach(servoPini);

  Servor.write(0);
  //Servoi.write(0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a= digitalRead(12); //From rainfall sensor
  int b= digitalRead(13); //From ir sensor
  if((a)==1 and (b)==0 )
  {
    Serial.println("\n");
    Serial.println("rainfall detected");
    Serial.println("Person not detected");
    digitalWrite(9,HIGH); //blue led
    digitalWrite(10,LOW); //red led
    digitalWrite(4,LOW); //buzzer
    digitalWrite(11,HIGH); //green led
    Servor.write(180);
    delay(100);
  }
  else if((a)==0 and (b)==1)
 {
  Serial.println("\n");
  Serial.println("rainfall not detected");
  Serial.println("Person detected");
  Servor.write(0);
  digitalWrite(4,HIGH); //buzzer
  digitalWrite(9,LOW); //blue led
  digitalWrite(11,LOW); //green led
  digitalWrite(10,HIGH); //red led
  delay(100);
 }
 else if(a==0 and b==0)
 {
  Serial.println("\n");
  Serial.println("Rainfall not detected");
  Serial.println("Person not detected detected");
  digitalWrite(10,LOW);//red led
  digitalWrite(11,HIGH);// green led
  digitalWrite(9,LOW); // blue led
  digitalWrite(4,LOW); //buzzer
  Servor.write(0);
  delay(100);
  //digitalWrite(11,HIGH);
 }
 else if(a==1 and b==1)
 {
  Serial.println("\n");
  Serial.println("Rainfall Detected");
  Serial.println("Person detected");
  Servor.write(0);
  digitalWrite(10,HIGH); //red led
  digitalWrite(4,HIGH); //buzzer
  digitalWrite(11,LOW); //green led
  digitalWrite(9,HIGH); //blue led
  delay(100);
 }
}

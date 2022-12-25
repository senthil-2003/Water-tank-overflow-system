#define trigger 10

#define echo 11

#define relay 8

#define buzzer 12


float time=0,distance=0;

int temp=0; 


void setup()

{
 pinMode(trigger,OUTPUT);

 pinMode(echo,INPUT);

 pinMode(relay, OUTPUT);

 pinMode(buzzer, OUTPUT);

 delay(2000);

}

void loop()

{

 digitalWrite(trigger,LOW);

 delayMicroseconds(2);

 digitalWrite(trigger,HIGH);

 delayMicroseconds(10);

 digitalWrite(trigger,LOW);

 delayMicroseconds(2);

 time=pulseIn(echo,HIGH);

 distance=time*340/20000;

 Serial.print(distance);

Serial.print("Cm");

 delay(2000);

 if(distance<12 && temp==0)

 {

     digitalWrite(relay LOW);

     digitalWrite(buzzer, HIGH);

     Serial.print("Water Tank Full ");

     delay(2000);

     digitalWrite(buzzer, LOW);

     delay(3000);

     temp=1;

 }

 

  else if(distance<12 && temp==1)

 {

     digitalWrite(relay, LOW);

     Serial.print("Water Tank Full ");

     delay(5000);

 }

 

 else if(distance>30)

 {

   digitalWrite(relay, HIGH);


  Serial.print("LOW Water Level");

   delay(5000);

   temp=0;

 }

}
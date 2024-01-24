// Potansiyometre ile servo motorun açısını ayarlama uygulaması
#include<Servo.h>

Servo smotor;

void setup()
{
  smotor.attach(9);
}


void loop()
{
int oku = analogRead(A0); //A0 dan analog bilgiyi oku ve "oku" isimli değişkene sakla - "0-1023"
int aci = map(oku,0,1023,0,180);
smotor.write(aci); //"0-180"
delay(50);
    
}
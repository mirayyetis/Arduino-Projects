#include<Servo.h>

int trigpin=9;
int echopin=10;
int kirmizi=4;
int sari=3;
int yesil=2;
long sure;
long uzaklik;
int buzzerpin=7;
Servo servo1;
int aci;

void setup()
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(kirmizi,OUTPUT);
  pinMode(sari,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  servo1.attach(11);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigpin, LOW);  // Daha öncesinde bu pinnde veri olma ihtimalinden dolayı bu pini low'a çakiyoruz.
  delayMicroseconds(2); 
  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigpin, LOW);
  
  // pulseIn methodu bir dijial pinin HIGH iken LOW yapılması arasındaki süreyi veya LOW iken HIGH yapılması arasında geçen süreyi hesaplamak için kullanılır.
  
  sure=pulseIn(echopin,HIGH); // Normalde echo pini LOW fakat trig pininden çıkan ışın bir cisme çarpıp tekrar mesafe sensörünün echo pinine ulaştığında HIGH olmuş oldu.
  uzaklik=(sure/2)/29.154; // uzaklik=(sure/2)*0.0343;
  
  Serial.print("Sinyal:");
  Serial.print(sure);
  Serial.println(" hareket etmistir.");

  Serial.print("Mesafe:");
  Serial.print(uzaklik);
  Serial.println(" CM");
  delay(1000);

  if (uzaklik < 10)
  {
    digitalWrite(kirmizi, HIGH);
    digitalWrite(sari, HIGH);
    digitalWrite(yesil, HIGH);
    digitalWrite(buzzerpin, HIGH);
    rotateServo();
    delay(1000);
    digitalWrite(buzzerpin, LOW);
    stopServo();
    delay(1000);

      
  }
  else if (uzaklik >= 10 && uzaklik < 30)
  {
    digitalWrite(kirmizi, LOW);
    digitalWrite(sari, HIGH);
    digitalWrite(yesil, HIGH);
    digitalWrite(buzzerpin, LOW);
    stopServo();
  }
  else if (uzaklik >= 30 && uzaklik <= 50)
  {
    digitalWrite(kirmizi, LOW);
    digitalWrite(sari, LOW);
    digitalWrite(yesil, HIGH);
    digitalWrite(buzzerpin,LOW);
    stopServo();
  }
  else
  {
    digitalWrite(kirmizi, LOW);
    digitalWrite(sari, LOW);
    digitalWrite(yesil, LOW);
    digitalWrite(buzzerpin,LOW);
    stopServo();

  }
  delay(1000);
}

void rotateServo() {
  // Servo motoru 90 derece döndür
  servo1.write(90);
}

void stopServo() {
  // Servo motoru durdur
  servo1.write(0);
}

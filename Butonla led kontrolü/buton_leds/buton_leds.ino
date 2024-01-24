int leds[]={6,7,8,9};
int buton=3;
int mode=1;

void setup()
{
  for(int i=0; i<4; i++){
    pinMode(leds[i],OUTPUT);
  }
  Serial.begin(9600);
  pinMode(buton,INPUT);
}

void loop()
{
 int durum=digitalRead(buton);
  if(durum ==1){
     mode*=-1;
    delay(50);
  }
  if(mode==1){
    ileri();
  }
  else{
    geri();
  }
}

void ileri(){
  Serial.println("ileri calisiyor");
  for(int i=0; i<4; i++){
    digitalWrite(leds[i],HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);
  }
}
  void geri(){
    Serial.println("geri calisiyor");
    for(int i=3; i>=0; i--){
    digitalWrite(leds[i],HIGH);
    delay(200);
    digitalWrite(leds[i],LOW);
  }
  }
    
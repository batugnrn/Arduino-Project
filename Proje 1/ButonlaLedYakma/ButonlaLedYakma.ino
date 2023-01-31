#define Button 8
#define Led 10

int butonDurum=0;

void setup() 
{ 

  pinMode(Button, INPUT);
  pinMode(Led, OUTPUT);

}

void loop() 
{
  
  butonDurum = digitalRead(Button);
  if(butonDurum==1)
  {
    digitalWrite(Led,HIGH);
  }
  else
  {
    digitalWrite(Led,LOW);
  }

}

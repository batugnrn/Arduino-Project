#include <dht11.h>
int dhtPin = 4;
dht11 dht_sensor;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void loop()
{
  // put your main code here, to run repeatedly:
  int  chk = dht_sensor.read(dhtPin);
  Serial.print("NEM ORANI: ");
  Serial.println((float)dht_sensor.humidity,2);

  Serial.print("SICAKLIK ORANI: ");
  Serial.println((float)dht_sensor.temperature,2);

  delay(100);
}

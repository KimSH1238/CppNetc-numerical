#include <DHTesp.h>
#define DHT_PIN D4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0; i<256; i++)
  {
    analogWrite(D2, i);
    dalay(30);
  }
for (int i=255; i>0; i--;)
  {
    analogWrite
  }
}

#include <DHT.h>
#define DHT_PIN D4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
float h =dht.readHumidity();
float t = dht.readTemperature();

Serial.print("Humidity : ");
Serial.println(h);
Serial.print("Temperature : ");
Serial.println(t);
}

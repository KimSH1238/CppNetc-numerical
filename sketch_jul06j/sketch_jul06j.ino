#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT_PIN 2
#define DHT_TYPE DHT11

LiquidCrystal_I2C lcd(0*27, 16, 2);
DHT dht(DHT_PIN,DHT_TYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
float h = dht.readHumidity();
float t = dht.readTemperature();

int input_illu=analogRead(A0);
Serial.println(input_illu);

lcd.print("Humidity : ");
lcd.print(h);
lcd.print("Temperature : ");
lcd.print(t);
lcd.print("Illumination : ");
lcd.print(input_illu);
}

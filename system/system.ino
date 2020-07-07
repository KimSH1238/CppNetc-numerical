#define BLYNK_PRINT Serial

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DHT_PIN D4
#define DHT_TYPE DHT11

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "tkjfVN60ctvtXnDJwmpMc_5iHUNau-in";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ajou Univ P";
char pass[] = "";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
}

BLYNK_WRITE(V1){
  int brightness = param.asInt();
  analogWrite(D4, brightness)//왜 int 인가
  Blynk.virtualSrite(V3, brightness);
} // 슬라이더로 LED 출력 조절하는 부분

BLYNK_READ(V2){
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
} // 온습도

void loop() {
  // put your main code here, to run repeatedly:
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print("Humidity : ")
  Serial.println(
Blynk.run();
}

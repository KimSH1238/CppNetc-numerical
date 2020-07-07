// 디바이스에서 서버로 알림을 주는 방식

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

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
}

BLYNK_READ(V0){
  int adcValue = analogRead(A0);
  float voltage = adcValue*33/1024.0;
  float temp=100.0*voltage -50;
  Blynk.virtualWrite(V0, temp);

  if(isnan(T) || isnan(h)){
    return;
  }

  if(t>40){
    Blynk.notify(String("temp is to high : ")+t);
  }
  if(h>70){
    Blynk.notify(String("Humidity is to high : ")+h);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int signalLevel = analogRead(A0);
  float voltage = signalLevel*3.3/1024.0;
  float temp = 100.0*voltage - 50;
  Serial.println(temp, 1);
  delay(300);
Blynk.run();
}

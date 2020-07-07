#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Servo.h>

#define LED_RED D2
#define LED_YEL D3
#define LED_GRE D5

Servo servo;

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
servo.attach(D4);

pinMode(LED_RED, OUTPUT);
pinMode(LED_YEL, OUTPUT);
pinMode(LED_GRE, OUTPUT);
}

BLYNK_READ(V0){
    int i = analogRead(A0);
}

BLYNK_READ(V1){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Blynk.virtualWrite(V0, temp);
  if(h>70){
    Blynk.notify("humidity is to high : "+h);
  }
  if(t>40){
    Blynk.notify("Temperature is to high : "+t);
  }
}

BLYNK_WRITE(V2){
//  analogWrite(LED_RED, t) 일때 전역변수 지정하는 방법?
//  analogWrite(LED_YEL, h) 마찬가지
}

BLYNK_WRITE(V3){
  servo.write(param.asInt());
}

void loop() {
  // put your main code here, to run repeatedly:
  float i = analogRead(A0);
  int input = map(analogRead(A0), 0, 1024, 255);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  analogWrite(LED_GRE, input);
//  analogWrite(LED_RED, 특정한 조건);
//  analogWrite(LED_YEL, 특정한 조건);
// 혹은 digitalWrite 로 하고, 조건문을 주는 것도 괜찮은 선택이다.

// servo 더 해야한다.
  
  Serial.println(i, 1); // 여기 1이 무슨 뜻으로 들어가는지 모르겠다.
  if(h>70){
    Serial.print("humidity is to high : ",+h);
  }
  if(t>40){
    Serial.print("temperature is to high : ",+t);
  }
  delay(300);
Blynk.run();
}

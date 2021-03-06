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

BLYNK_WRITE(V1)
{
int r = param[0].asInt();
int g = param[1].asInt();
int b = param[2].asInt();

analogWrite(D2, r);
analogWrite(D3, g);
analogWrite(D4, b);
}

void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}

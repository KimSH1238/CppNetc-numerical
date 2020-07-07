/* This sketch sends data via HTTP GET requests to esp8266-shop.com and returns the website in html format which is printed on the console */
#include <ESP8266WiFi.h>
const char* ssid = "<ssid>"; //replace with your own wifi ssid
const char* password = "<wifi_pw>"; //replace with your own //wifi ssid password 
const char* host = "<ip주소>";
void setup() {
  Serial.begin(115200);
  delay(10); // We start by connecting to a WiFi network Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default, would try to act as both a client and an access-point and could cause network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;
int humi = 0;
int temp = 0;

void loop() {
  delay(5000);
  ++value;
  Serial.print("connecting to ");
  Serial.println(host); // Use WiFiClient class to create TCP connections
  WiFiClient client;


  //실제 연동 port 
  const int httpPort = 8000;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // 요청하는 파라미터작성
  String url = "/input/";
//    url += humi;
//    url += "/";
//    url += temp;
  //  url += param2;
   
  Serial.print("Requesting URL: ");
  Serial.println(url); // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000)
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  } // Read all the lines of the reply from server and print them to Serial
  while (client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
}
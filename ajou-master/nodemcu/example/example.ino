
#include <ESP8266WiFi.h>
#include <Servo.h>
#define ledPin D2

const char* ssid = "makeitnow";
const char* password = "19880724";
Servo myservo;
WiFiServer server(80); // 80번 포트를 열어준다.

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  myservo.attach(D4);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected!!");

  server.begin();
  Serial.println("Server Started");

  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Serial.println("");
}

void loop() {

  WiFiClient client = server.available();
  if(!client){
    return;
  }

  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  String request = client.readStringUntil('\r');
  client.flush();

  int value=0;
  //indexOf(val) 없으면 -1을 리턴

  if(request.indexOf("/SERVO=0") != -1){
    myservo.write(0);
    value = 0;
  }
  
  if(request.indexOf("/SERVO=90") != -1){
    myservo.write(90);
    value = 90;
  }
  
  if(request.indexOf("/SERVO=180") != -1){
    myservo.write(180);
    value = 180;
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type : text/html");
  client.println("Connection: close");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("LED is turned ");
  if(value == 180){
    client.print("180");
  }else if(value == 90){
    client.print("90");
  }
  else{
    client.print("0");
  }
  client.println("<br><br>");
  client.println("<a href=\"/SERVO=0\"\"><button>0degree</button></a>");
  client.println("<a href=\"/SERVO=90\"\"><button>90degree</button></a>");
  client.println("<a href=\"/SERVO=180\"\"><button>180degree</button></a>");
  client.println("</html>");

  delay(1);
  client.stop();
  Serial.println("Client disconnected!!");
  Serial.println();
}

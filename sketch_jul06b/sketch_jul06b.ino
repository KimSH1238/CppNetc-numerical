#define LED_RED D2
#define LED_YEL D4

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //board rate
pinMode(LED_RED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_RED, HIGH);
digitalWrite(LED_YEL, LOW);
Serial.print("LED RED status : ");
Serial.println("text");
delay(1000);

digitalWrite(LED_RED, LOW);
digitalWrite(LED_YEL, HIGH);
Serial.print("LED RED status : ");
Serial.println("text");
delay(1000);
}

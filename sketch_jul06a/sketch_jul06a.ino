#define LED_RED D2
#define LED_YEL D4

void setup() {
  // put your setup code here, to run once:
pinMode(LED_RED, OUTPUT);
pinMode(LED_YEL, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED_RED, LOW);
digitalWrite(LED_YEL, LOW);
delay(1000);
digitalWrite(LED_RED, HIGH);
digitalWrite(LED_YEL, HIGH);
delay(1000);
}

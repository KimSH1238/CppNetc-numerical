#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
myservo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
long int val = map(analogRead(A0), 0, 1024, 180);
myservo.write(val);
}

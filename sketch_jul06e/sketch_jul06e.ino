void setup() {
  // put your setup code here, to run once:
pinMode(D2, OUTPUT);
pinMode(D4, INPUT_PULLUP);
pinMode(D6, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(D4)==LOW)
  {
    digitalWrite(D2, HIGH);
    delay(100);
  }
if(digitalRead(D6) ==LOW)
  {
    digitalWrite(D2, LOW);
    delay(100);
  }
}

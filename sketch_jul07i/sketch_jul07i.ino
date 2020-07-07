// virtual 안되서 직접 시리얼 보드에 받는 코딩

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int signalLevel = analogRead(A0);
float voltage = signalLevel*3.3/1024.0;
float temp = 100.0*voltage - 50;
Serial.println(temp, 1);
delay(300);
}

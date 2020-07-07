void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int input = analogRead(A0);
float voltage = input*3.3/1024;
Serial.print(voltage,4);
Serial.println("V");
}

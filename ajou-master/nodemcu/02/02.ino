void setup() {
   pinMode(D2, OUTPUT);  // D2번핀에 연결
   pinMode(D4, OUTPUT);
}

void loop() {
   digitalWrite(D2, HIGH);  // 불 켜기
   digitalWrite(D4, LOW); // 불 켜기
   delay(1000);
   digitalWrite(D2, LOW); // 불 끄기
   digitalWrite(D4, HIGH);  // 불 끄기
   delay(1000);
}

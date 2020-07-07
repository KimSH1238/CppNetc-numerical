#define LED_RED D2
#define LED_YEL D4

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //board rate
pinMode(LED_RED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0) // 시리얼 모니터에 값이 있다면
  {
    int inputdata = Serial.parseInt(); //int값으로 값을 가져온다
  Serial.print("input data : ");
  Serial.println(inputdata);

  if(inputdata==1)
    {
    digitalWrite(LED_RED, HIGH);
    }
  else
    {
    digitalWrite(LED_RED, LOW);
    }
  }
}

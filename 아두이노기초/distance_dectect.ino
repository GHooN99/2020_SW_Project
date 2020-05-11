#include "Math.h"
int ledRed = 8;
int ledGreen = 9;
int buzzer = 10;
int trig = 11;
int echo = 12;


void setup()
{
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

}


void loop()
{
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);

  // 초음파의 속도는 초당 340미터를 이동하거나, 29마이크로초 당 1센치를 이동합니다.
  // 따라서, 초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2 입니다.
  float distance = duration / 29.0 / 2.0;

  // 측정된 거리 값를 시리얼 모니터에 출력합니다.
  Serial.print(distance);
  Serial.println("cm");

  if (distance < 20)
  {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
     digitalWrite(buzzer, HIGH);
    delay(5*distance);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
  }
  delay(130);
}

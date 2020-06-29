
int ledRed1 = 8;
int ledYellow1 = 9;
int ledGreen1 = 10;

int ledRed2 = 11;
int ledYellow2 = 12;
int ledGreen2 = 13;

int echo1 = 3;
int trig1 = 4;

int echo2 = 5;
int trig2 = 6;

float setUSenor(int Pin_trig,int Pin_echo,int num)
{
  digitalWrite(Pin_trig, LOW);
  digitalWrite(Pin_echo, LOW);
  delayMicroseconds(2);
  digitalWrite(Pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Pin_trig, LOW);

  unsigned long duration = pulseIn(Pin_echo, HIGH);

  // 초음파의 속도는 초당 340미터를 이동하거나, 29마이크로초 당 1센치를 이동합니다.
  // 따라서, 초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2 입니다.
  float distance = duration / 29.0 / 2.0;

  // 측정된 거리 값를 시리얼 모니터에 출력합니다.
  Serial.print(num);
  Serial.print(": ");
  Serial.print(distance);
  Serial.println("cm");
  return distance;
}


void setup()
{
  Serial.begin(9600);
  pinMode(ledRed1, OUTPUT);
  pinMode(ledYellow1, OUTPUT);
  pinMode(ledGreen1, OUTPUT);
  
  pinMode(ledRed2, OUTPUT);
  pinMode(ledYellow2, OUTPUT);
  pinMode(ledGreen2, OUTPUT);

  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);

  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
}


void loop()
{


  float distance1, distance2;
  distance1 = setUSenor(trig1, echo1, 1);
  distance2 = setUSenor(trig2, echo2, 2);


  if (distance1 > 20)
  {
    digitalWrite(ledRed1, LOW);
    digitalWrite(ledYellow1, LOW);
    digitalWrite(ledGreen1, HIGH);
  }
  else if (distance1 > 10)
  {
    digitalWrite(ledRed1, LOW);
    digitalWrite(ledYellow1, HIGH);
    digitalWrite(ledGreen1, LOW);
  }
  else if (distance1 <= 10)
  {
    digitalWrite(ledRed1, HIGH);
    digitalWrite(ledYellow1, LOW);
    digitalWrite(ledGreen1, LOW);
  }



  if (distance2 > 20)
  {
    digitalWrite(ledRed2, LOW);
    digitalWrite(ledYellow2, LOW);
    digitalWrite(ledGreen2, HIGH);
  }
  else if (distance2 > 10)
  {
    digitalWrite(ledRed2, LOW);
    digitalWrite(ledYellow2, HIGH);
    digitalWrite(ledGreen2, LOW);
  }
  else if (distance2 <= 10)
  {
    digitalWrite(ledRed2, HIGH);
    digitalWrite(ledYellow2, LOW);
    digitalWrite(ledGreen2, LOW);
  }


  delay(130);
}

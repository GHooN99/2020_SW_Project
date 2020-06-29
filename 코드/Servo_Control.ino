
//
#include <Servo.h>
#define _INITcm 30
#define PET 1
#define GLASS 3
#define CAN 2
#define PAPER 4
#define angle_LEFT 45
#define angle_RIGHT 135

Servo moter_top;
Servo moter_left;
Servo moter_right;
Servo welcome_moter;

int echo = 3;
int trig = 4;
float distance = 0;
float getDistance(int Pin_trig, int Pin_echo)
{
  digitalWrite(Pin_trig, LOW);
  digitalWrite(Pin_echo, LOW);
  delayMicroseconds(2);
  digitalWrite(Pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Pin_trig, LOW);

  unsigned long duration = pulseIn(Pin_echo, HIGH);

  float d = duration / 29.0 / 2.0;
  return d;
}
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  moter_top.attach(8);
  moter_left.attach(9);
  moter_right.attach(10);
  welcome_moter.attach(7);

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

}
void setMoterByClass(int class_of_trash)
{
  switch (class_of_trash)
  {
  case PET:
    moter_top.write(angle_RIGHT);
    delay(50);
    moter_left.write(angle_RIGHT);

    break;
  case CAN:
    moter_top.write(angle_RIGHT);
    delay(50);
    moter_left.write(angle_LEFT);

    break;

  case GLASS:
    moter_top.write(angle_LEFT);
    delay(50);
    moter_right.write(angle_RIGHT);

    break;
  case PAPER:
    moter_top.write(angle_LEFT);
    delay(50);
    moter_right.write(angle_LEFT);

    break;

  default:
    break;
  }
  delay(300);
  welcome_moter.write(0);
  delay(5000); //5초 기다림
}
void setMoter()
{
  moter_left.write(90);
  delay(50);
  moter_right.write(90);
  delay(50);
  moter_top.write(90);
  delay(50);
  welcome_moter.write(90);
  delay(50);
}
void loop()
{
  int cnt = 0;
  setMoter();

  distance = getDistance(trig, echo);

  if (distance <= _INITcm)
  {
    Serial.println('1');
    tone(13,880);
    delay(60);
    noTone(13);
    delay(10);
    tone(13,880);
    delay(100);
    noTone(13);
    delay(100);
    while (true)
    {
      if (Serial.available())   //시리얼 통신이 오면 
      {
        int class_of_trash = Serial.read();  //분류 결과값 읽어들임
        if (1 <= class_of_trash && class_of_trash <= 4)
          setMoterByClass(class_of_trash);    // 결과에 따라 모터 움직임
        else
        {
          
            tone(13,880);
            delay(200);
              noTone(13);
            delay(200);
               tone(13,880);
              delay(200);
              noTone(13);
             delay(200);
              tone(13,880);
            delay(200);
              noTone(13);
            delay(200);
             delay(50);
          Serial.println('1');
             break;
        }
        delay(50);
        Serial.println('1');
        break;    
      }
      else
      {
        cnt++;
        delay(50);
        if (cnt > 100)  //5초동안 아무일도 없으면 끝
          break;
      }
    }

  }
  else
  {
    delay(50);
  }

}

#include <Servo.h> //서보 라이브러리를 불러옵니다.

Servo myservo1;  // 서보를 제어할 서보 오브젝트를 만듭니다.
Servo myservo2; 
Servo myservo3; 

int pos = 0;     // 서보 위치를 저장할 변수를 선언합니다.

void setup()
{
  Serial.begin(19200); // 시리얼 통신 시작 
  myservo1.attach(9);  // 핀 9의 서보를 서보 오브젝트에 연결합니다.
  myservo2.attach(10);
  myservo3.attach(11);

}


void loop()
{
    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    
 if (Serial.available())  
  {
    int n = Serial.read();   // 파이썬에서 신호를 가져옴 
      delay(30);

    if (n == 1)   
    {
      myservo1.write(120);
      myservo2.write(120);
      delay(2000);
    }
    else if (n == 2)
    {
     myservo1.write(120);
      myservo2.write(60);
      delay(2000);
    }
    else if(n==3)
    {
     myservo1.write(60);
      myservo3.write(120);
      delay(2000);
    }
    else if(n==4)
    {
     myservo1.write(60);
      myservo3.write(60);
      delay(2000);
    }

  }
  
}

### 프로젝트에 사용된 코드

<hr>

#### 아두이노

- Storage_Check.ino -> 쓰레기통의 용량을 초음파 센서로 체크하여 LED로 용량을 표시하는 코드

- Servo_Control.ino -> 아두이노와 파이썬의 시리얼 통신을 통해 신호를 주고 받고 그에 따라 서보 모터에 명령을 내리는 코드

#### 파이썬 

- main.py -> 학습된 모델을 불러오고 아두이노에서 신호를 받아 웹캠을 이용하여 물체를 분류한 후 아두이노에 다시 신호를 보내는 코드


#### 기타 

- 프로토 타입 -> 작은 모형을 만들때 사용한 코드

- mymodel.h5 , labels.txt -> Teachable Machine 으로 학습시킨 모델을 export 한 파일들

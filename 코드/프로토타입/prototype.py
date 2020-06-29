import cv2
import serial
import tensorflow.keras
import numpy as np
import time

np.set_printoptions(suppress=True)
t = ["pet","coke","glass","None"]

#ard = serial.Serial("COM8", 9600)     # 아두이노에 연결  보드레이트 설정

time.sleep(3)


model = tensorflow.keras.models.load_model('keras_model.h5')       # 모델 불러오기


data = np.ndarray(shape=(1, 224, 224, 3), dtype=np.float32)     # shape = (1,224,224,3)
cap = cv2.VideoCapture(0)
time.sleep(2)

# 비디오 224,224 크기 지정
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 224)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 224)

k = 0
cnt = 0  # 몇번 유지 되나


while cap.isOpened():
    # 카메라 프레임 읽기
    success, frame = cap.read()
    if success:
        # 프레임 출력
        cv2.imshow('Camera Window', frame)
        # ESC를 누르면 종료
        key = cv2.waitKey(1) & 0xFF
        if (key == 27):
            break
    frame_r = cv2.resize(frame, (224, 224))
    image_array = np.expand_dims(frame_r, axis=0)

    normalized_image_array = (image_array.astype(np.float32) / 127.0) - 1

    data[0] = normalized_image_array

    prediction = model.predict(data)
    print(prediction)

    if (k == np.argmax(prediction) + 1):        # 이전의 결과가 현재와 같을때
        cnt += 1        # 카운트 수 증가
    else:
        cnt = 0

    k = np.argmax(prediction) + 1

    #print('k :', k)
    #print('cnt :', cnt)
    #print(t[k-1])

    if(cnt == 5):           # 같은 결과가 5번 유지 되면
        try:
           # ard.write([k])      # 아두이노에 결과 값 신호를 보낸다
            print(t[k-1])
            cnt = 0             # 카운트 초기화
            time.sleep(3)

        except:
            print("Error")
            pass
    time.sleep(0.3)

cap.release()
cv2.destroyAllWindows()
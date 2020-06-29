import cv2
import serial
import tensorflow.keras
import numpy as np
import time

np.set_printoptions(suppress=True)
t = ["pet","coke","glass","None"]

ard = serial.Serial("COM8", 9600)     # 아두이노에 연결  보드레이트 설정

time.sleep(1)

model = tensorflow.keras.models.load_model('mymodel.h5')       # 모델 불러오기

data = np.ndarray(shape=(1, 224, 224, 3), dtype=np.float32)     # shape = (1,224,224,3)
cap = cv2.VideoCapture(0)
time.sleep(1)

# 비디오 224,224 크기 지정
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 224)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 224)

k = 0
cnt = 0  # 몇번 유지 되나

# 세팅 완료

print("READY!!!")
while True:
    s = [0]*5
    if ard.readable():
        a = ard.readline()
        if int(a[2]) == 10:
            print("OK")
            time.sleep(1)
            for i in range(4):
                success, frame = cap.read()
                frame_r = cv2.resize(frame, (224, 224))
                image_array = np.expand_dims(frame_r, axis=0)

                normalized_image_array = (image_array.astype(np.float32) / 127.0) - 1

                data[0] = normalized_image_array

                prediction = model.predict(data)
                print(prediction)

                s[np.argmax(prediction)]+=1  # 카운트 증가
                time.sleep(0.8)

            result = s.index(max(s))+1
            print(result)
            ard.write([result])
            a = ard.readline()
            if int(a[2]) == 10:
                print("OK out!")
        else:
            continue
    else:
        continue


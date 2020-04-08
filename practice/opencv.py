import cv2
import serial
import tensorflow.keras
import numpy as np
import time

np.set_printoptions(suppress=True)


model = tensorflow.keras.models.load_model('converted_keras/keras_model.h5')


data = np.ndarray(shape=(1, 224, 224, 3), dtype=np.float32)
cap = cv2.VideoCapture(0)


while cap.isOpened():
    # 카메라 프레임 읽기
    success, frame = cap.read()
    frame_r = cv2.resize(frame, (224, 224))
    if success:
        # 프레임 출력
        cv2.imshow('Camera Window', frame_r)
        # ESC를 누르면 종료
        key = cv2.waitKey(1) & 0xFF
        if (key == 27):
            break
    image_array = np.expand_dims(frame_r, axis=0)

    print(image_array.shape)
    normalized_image_array = (image_array.astype(np.float32) / 127.0) - 1

    data[0] = normalized_image_array

    prediction = model.predict(data)
    print(prediction)
    print(np.argmax(prediction)+1)

    time.sleep(0.1)

cap.release()
cv2.destroyAllWindows()





// 아두이노 내장 LED 점멸 예제 (13번핀)

void setup()
{
	pinMode(13, OUTPUT);
}
void loop()
{
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);

}


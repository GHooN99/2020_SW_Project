// �迭 ����?? �̰� �ǳ� 

int ledSet[5] = { 1,2,3,4,5 };

void setup()
{
	for(int i=0;i<5;i++)
	pinMode(ledSet[i], OUTPUT);
}
void loop()
{
	for (int i = 0; i < 5; i++)
	{
		digitalWrite(ledSet[i], HIGH);
		delay(800);
		digitalWrite(ledSet[i], LOW);
	}
}
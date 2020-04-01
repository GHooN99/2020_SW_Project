
int led = 5;

void setup()
{
		pinMode(led, OUTPUT);
}
void loop()
{
	for (int i = 0; i < 255; i+=5)
	{
		analogWrite(led, i);
		delay(50);
	}
	delay(500);
}
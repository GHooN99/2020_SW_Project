// led 2°³ Á¡¸ê 

int led1 = 5;
int led2 = 6;

void setup()
{
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);

}
void loop()
{
	digitalWrite(led1, HIGH);
	digitalWrite(led2, LOW);
	delay(800);

	digitalWrite(led1, LOW);
	digitalWrite(led2, HIGH);
	delay(800);

}
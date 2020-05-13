// vs2017 , visual micro 작동 테스트 
void setup() 
{
	Serial.begin(9600);

}
// the loop function runs over and over again until power down or reset
void loop() 
{
	Serial.println("hello");
	delay(1000);
	printNum(10);
	

}
void printNum(int x)
{
	Serial.println(x);
	delay(100);
}
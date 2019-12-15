int number1 = 0, number2 = 0;

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(100);
}

void loop()
{
  while(Serial.available() == 0);
  number1 = Serial.parseInt();
  Serial.println(number1);
  while(Serial.available() == 0);
  number2 = Serial.parseInt();
  Serial.println(number2);
  Serial.println(number1 + number2);
}

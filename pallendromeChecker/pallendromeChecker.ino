#include "TwoPointer.h"

String data_until_now = "";

TwoPointer twoPointer(false);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0);
  String input = Serial.readString();
  data_until_now += input;
  Serial.println(data_until_now);
  if(twoPointer.checker(data_until_now)) 
     digitalWrite(LED_BUILTIN, HIGH);
  else
     digitalWrite(LED_BUILTIN, LOW);
}

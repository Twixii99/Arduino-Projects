#include "mores.h"

const int TIME = 200;
Mores mores_conv(false);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(LED_BUILTIN, OUTPUT);
} 

void loop() {
  String input;
  while(Serial.available() > 0);
  input = Serial.readString();
  String ans = mores_conv.converter(input);
  ShowLightOutPut(ans);
}

void ShowLightOutPut(String ans) {
  for(int i = 0; i < ans.length(); ++i){
     if(ans.charAt(i) == '.')
         LightNthTimes(1);
     else if(ans.charAt(i) == '-')
         LightNthTimes(3);
     else {
         digitalWrite(LED_BUILTIN, LOW);
         delay(7 * TIME);
     }
  }
}

void LightNthTimes(int waiting) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(TIME * waiting);
    digitalWrite(LED_BUILTIN, LOW);
    delay(TIME);  
}

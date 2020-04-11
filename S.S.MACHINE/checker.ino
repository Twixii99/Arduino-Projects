#include "Checker.h"

#define CHECKER_LASER 2
#define CHECKER_LDR 0
#define RED_LED 4
#define GREEN_LED 5

Checker checker = Checker();
void setup() {
  // put your setup code here, to run once:
  // initialize serial frequency to 9600
  Serial.begin(9600);
  //initialize the program
  checker.welcomeMessage();
  // start analog AR pin (not necessary)
  analogReference(DEFAULT);
  // modes of pins
  pinMode(CHECKER_LASER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  // initialize output of the selected pins to zero
  digitalWrite(CHECKER_LASER, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(!(Serial.available() == 0)) {
    checker.converter(Serial.readString());
    sender_reciver();
  }
}

void sender_reciver() {
  byte idx = 0, is = 0;
  bool check = 1;
  while(idx != checker.lengthOfData and check) {
    digitalWrite(CHECKER_LASER, checker.data[idx++] ? HIGH : LOW);
    delay(1500);
    digitalWrite(CHECKER_LASER, LOW);  // here i send signal 1 or 0 then close laser
    ul t1 = millis(); // الul و period اللى تحتها متعرفين فى الheader لو مش عارف
    while(millis() - t1 <= PERIOD) // الفكرة بتاعت millis هتفضل تقرى لحد ثانية واحدة اللى انت ظابطها فين ايوه برافو فى S.S.machine تمام
    // هنا انا عامل is دى عشان اعمل check بس انا مش ضامن analogRead شغالة ازاى عشان اقارن بيها على طول فالفكرة انى القط ع طول اى حاجة بتتغير
      is = analogRead(CHECKER_LDR) <= 800; 
    if(is == checker.output[idx])
      digitalWrite(GREEN_LED, HIGH);
    else {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      check = 0;
    }
  }
}

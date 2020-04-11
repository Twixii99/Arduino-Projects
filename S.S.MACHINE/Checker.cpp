#include "Checker.h"

Checker::Checker() {}

void Checker::welcomeMessage() {
  Serial.println("Willkommen zu unserem Programm!!!");
}

void Checker::converter(String str) {
  this->initial_state = 0; 
  this->lengthOfData = str.length();
  this->data = new byte[this->lengthOfData];
  for(int i = 0; i < this->lengthOfData; ++i)
    data[i] = str[i] - 48; 
  this->accurate_output();
}

void Checker::accurate_output() {
  this->output = new byte[this->lengthOfData];
  for(int i = 0; i < this->lengthOfData; ++i) {
    output[i] = data[i] and initial_state;
    initial_state = data[i] xor initial_state;
  }
}

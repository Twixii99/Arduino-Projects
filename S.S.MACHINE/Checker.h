#ifndef Checker_H_
#define Checker_H_

#if(ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

typedef unsigned long ul;
const ul PERIOD = 1000;

class Checker {
  public:
    Checker();
    void welcomeMessage();
    void converter(String);
    
  private:
    void accurate_output();

  private:
    bool initial_state = 0;
    
  public:
    byte lengthOfData;
    byte *output;
    byte *data;
};

#endif

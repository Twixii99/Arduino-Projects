#ifndef PARSER_H_
#define PARSER_H_

#if(ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define convert(x) ((byte *)x)
typedef unsigned long ul;

//time structure contains seconds, hours, minutes, day and day_ellipsed.
// day -> indicates "AM" or "PM" for simplicity 'P' or 'A'.
// day_ellipsed -> indicates if there is 24 hours had been ellipsed from the starting time of the program.
struct Time {
  byte seconds;
  byte minutes;
  byte hours;
  char day;
  byte day_ellipsed; // if it's 2 then 2 * 12 = 24 which is a day.
};

// date structure contains day, month and year.
struct Date {
  byte day;
  byte month;
  int year;
};

// pins connected to the lcd
const int rs = 5, en = 4, d4 = 3, d5 = 2, d6 = 1, d7 = 0;

// structure of the keypad
const byte ROWS = 4;
const byte COLS = 4;

const char keys[ROWS][COLS] = {
  {'1','2','3','u'},
  {'4','5','6','d'},
  {'7','8','9','r'},
  {'s','0','e','l'}
};

const byte rowPins[ROWS] = {6, 7, 8, 9}; //connect to the row pinouts of the keypad
const byte colPins[COLS] = {10, 11, 12, 13}; //connect to the column pinouts of the keypad

class Parser {
  private:
  // strction information
    Time timex;
    Date date;
  // chose date or time in the lcd display 
  // 0 for date and 1 for time
    bool current_row = 0;
  // Initialized date and time
    const char *upDate = "HDATE:23:08:1441"; // used Hijri date. 
    const char *upTime = "CTIME:00:00:00"; // starting time it could be any thing else.
  // data collector
    String dataCollector[2];  // records changes to use them after set Mode finished.
  public:
    Parser(char); // constructor function which has one parameter indicates if we start with "AM" or "PM" -> "PM" by default
    void printInitialData(); // prints initial data.
    void beginProgram(); // use this function to start the progrm
    void setDate();  // set date and time after each second left.
    void setTime();  // set date and time after each second left.
    void updateDate();   // set date and time after each set Mode.
    void updateTime();    // set date and time after each set Mode.
};

#endif

#include <LiquidCrystal.h>
#include <Keypad.h>
#include "Parser.h"

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad keypad = Keypad( makeKeymap(keys), convert(rowPins), convert(colPins), ROWS, COLS );

Parser::Parser(char x = 'P') {
  // starting display
  lcd.begin(16,2);
  // initialize time and date
  this->timex = {0, 0, 0, x, 0};
  this->date = {23, 8, 1441};
}

void Parser::beginProgram() {
  this->printInitialData();
  ul initialTime = millis();
  while(true) {
    char key = keypad.getKey();
    // if you enter some key except what equivelent to 's' which is set mode, the operation will continue as usual.
    if((millis() - initialTime >= 1000) && key != 's') {
      ++timex.seconds;
      if(timex.seconds == 60) { ++timex.minutes; timex.seconds = 0; }
      if(timex.minutes == 60) { ++timex.hours;  timex.minutes = 0;  }
      if(timex.hours == 12) { ++timex.day_ellipsed; timex.day = (timex.day == 'A' ? 'P' : 'A'); timex.hours = 0; }
      if(timex.day_ellipsed == 2) { ++date.day; timex.day_ellipsed = 0; }
      if(date.day == 31) { ++date.month; date.day = 1; }
      if(date.month == 13) { ++date.year; date.month = 1; }
      this->setDate();
      this->setTime();
      initialTime = millis();
    }
    // set Mode.
    else if(key == 's'){
      byte Cursor = 0;
      lcd.setCursor(Cursor, this->current_row);
      lcd.blink();
      for(char x = keypad.waitForKey(); x != 'e'; x = keypad.waitForKey()) {
        if(x == 'u' || x == 'd') {
          this->current_row = !this->current_row;     // if the cursor is at row 0 then if we clicked up it must be -1(funny) so circuilar to 1.
          lcd.setCursor(Cursor, this->current_row);
        } else if(x == 'r' || x == 'l') {
          if(x == 'r') ++Cursor;
          else --Cursor;
          Cursor %= 16;       // if the most right return to 0 and vise verse.
          lcd.setCursor(Cursor, this->current_row);
        } else {
          // impossible operations....
          // Hint: col 8 and 11 contains ':' colon
          if(x != 's' && Cursor != 8 && Cursor != 11 && !(Cursor == 15 && this->current_row) && Cursor > 5) {
            if(Cursor == 14 && this->current_row) {
              x = (timex.day == 'A' ? 'P' : 'A');
              timex.day = x;
              if(x == 'A') timex.day_ellipsed = 0;
              else timex.day_ellipsed = 1;
            }
            dataCollector[current_row][Cursor] = x;
            lcd.print(x);
          }
          lcd.setCursor(Cursor, this->current_row);
        }
      }
      // after finishing set mode. by pressing end button.
      // update what u made.
      this->updateDate();
      this->updateTime();
      lcd.noBlink();
      initialTime = millis();
    }
  }
}

void Parser::printInitialData() {
  // printing initial data
  lcd.print(this->upDate);
  lcd.setCursor(0,1);
  lcd.print(this->upTime + String(timex.day) + "M");
}

void Parser::setDate() {
  lcd.setCursor(0,0);
  // it just makes string builder for the date then print it to the LCD
  String updated_date = "";
  updated_date += "HDATE:";
  if(date.day < 10) updated_date += "0" + String(date.day) + ":";
  else updated_date += String(date.day) + ":";
  if(date.month < 10) updated_date += "0" + String(date.month) + ":";
  else updated_date += String(date.month) + ":";
  updated_date += String(date.year);
  this->dataCollector[0] = updated_date;
  lcd.print(updated_date);
}

void Parser::setTime() {
  lcd.setCursor(0,1);
  // it just makes string builder for time then print it to the LCD
  String updated_time = "";
  updated_time += "CTIME:";
  if(timex.hours < 10) updated_time += "0" + String(timex.hours) + ":";
  else updated_time += String(timex.hours) + ":";
  if(timex.minutes < 10) updated_time += "0" + String(timex.minutes) + ":";
  else updated_time += String(timex.minutes) + ":";
  if(timex.seconds < 10) updated_time += "0" + String(timex.seconds);
  else updated_time += String(timex.seconds);
  updated_time += String(timex.day);
  this->dataCollector[1] = updated_time;
  lcd.print(updated_time);
}

void Parser::updateDate() {
  date.day = (dataCollector[0][6] - 48) * 10 + (dataCollector[0][7] - 48);
  date.month = (dataCollector[0][9] - 48) * 10 + (dataCollector[0][10] - 48);
  date.year = (dataCollector[0][12]-48)*1000+(dataCollector[0][13]-48)*100+(dataCollector[0][14]-48)*10+(dataCollector[0][15]-48);
  if(date.day > 30) date.day = 30;
  if(date.month > 12) date.month = 12;
}

void Parser::updateTime() {
  timex.hours = (dataCollector[1][6] - 48) * 10 + (dataCollector[1][7] - 48);
  timex.minutes = (dataCollector[1][9] - 48) * 10 + (dataCollector[1][10] - 48);
  timex.seconds = (dataCollector[1][12] - 48) * 10 + (dataCollector[1][13] - 48);
  timex.day = dataCollector[1][14];
  if(timex.hours >= 12) timex.hours = 0;
  if(timex.minutes > 59) timex.minutes = 0;
  if(timex.seconds > 59) timex.seconds = 0;
}


/**
 * @author Mahmoud Kamal Mahmoud
 * @date friday April-17-2020
 * 
 * This progrm uses abstraction...
 * using two arduino libraries "LiquidCrystal" and "Keypad" besides a simple one built by us "Parser.h".
 * 
 */
 
#include "Parser.h"

// make instance of parser class found in the header file
Parser parser('A');

void setup() {
  parser = Parser('A');
}

void loop() {
  // start the progrm
  parser.beginProgram();
}

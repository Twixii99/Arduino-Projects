#include "mores.h"

Mores::Mores(bool need_help) {
    // helping message
    Serial.println("You have to send your data to serial monitor");
}

                          
String Mores::converter(String input){
    String str = "";
    for(int i = 0; i < input.length(); ++i) {
      for(int j = 0; j < 40; ++j) {
        if(input.charAt(i) == this->letters[j]) {
          str += this->mores_patterns[j] + ' ';
        }
      }
    }
    return str; 
}

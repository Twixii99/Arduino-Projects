#ifndef TWIXII
#define TWIXII

#if(ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Mores {

  private:
      // array of possible letters
      const char letters[40] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
                                      'w','x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',',', '.', '?', ' ' };

      // array of possible morse codes
      const String mores_patterns[40] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                                              "---", ".---.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
                                              "..---", "...--","....-", ".....", "-....", "--...", "---..", "----.","-----", "--..--", ".-.-.-", 
                                              "..--..", " "};
   public:

      // constructor of the Mores class set it's para to true if you need help of with nothing
      Mores(bool need_help = true);
      // the method that will convert letters to mores code
      String converter(String input);

   
};

#endif

#ifndef terex
#define terex

#if(ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class TwoPointer {
   public: 
        // The class constructor set true if you need help
        TwoPointer(bool need_help = true);

        // method of operations
        bool checker(String data_until_now);
   
   private:
};




#endif

#include "TwoPointer.h"

TwoPointer::TwoPointer(bool need_help){
  // helping statement
  if(need_help)
    Serial.println("you should enter letter by letter and send it to monitor to check for pallindrome or as you want");
}


bool TwoPointer::checker(String data_until_now) {
   for(int i = 0, j = data_until_now.length() - 1; i <= j; ++i, --j) {
      if(data_until_now.charAt(i) == data_until_now.charAt(j))
        continue;
      else
        return false;
   }return true;  
}

#include <iostream>
#include <string>

class SlowKeyboard {
 public:
  int enterTime(std::string time) {
    int min1 = time[0] - '0';
    int min2 = time[1] - '0';
    int sec1 = time[3] - '0';
    int sec2 = time[4] - '0';
    
    int timeClockSeconds = 0;
    int timeTyping;
    while(1){
      //timeTyping = 4 + (a==b?0:2) + (b==c?0:2) + (c==d?0:2) ;
      timeTyping = 4;
      if (min1==min2){
        timeTyping += 0;
      } else{
        timeTyping += 2;
      }
      if (min2==sec1){
        timeTyping += 0;
      } else{
        timeTyping += 2;
      }
      if (sec1==sec2){
        timeTyping += 0;
      } else{
        timeTyping += 2;
      }

      //terminate the loop function
      if (timeTyping <= timeClockSeconds) {
        return timeClockSeconds;
      }

      //increase the seconds
      sec2++;
      
      // if 00:09 --> 00:0(10) --> 00:10
      if(sec2==10){   
        sec2 = 0;
        sec1++;
      }

      // if 00:59 --> 00:60 --> 01:00
      if (sec1 == 6){
        sec1 = 0;
        min2++;
      }

      // if 09:00 --> 0(10):00 --> 10:00
      if(min2 == 10){
        min2 = 0;
        min1++;
      }
    
      // if 59:59 --> 60:00 --> 00:00
      if(min1 == 6){
        min1 = 0;
      }

      timeClockSeconds++; // a second has pass
    }
   }
};

int main() {
  SlowKeyboard slowKeyboard;

  // Example 0
  std::cout << slowKeyboard.enterTime("59:56") << std::endl;  // Output: 4

  // Example 1
  std::cout << slowKeyboard.enterTime("59:59") << std::endl;  // Output: 6

  // Example 2
  std::cout << slowKeyboard.enterTime("33:12") << std::endl;  // Output: 8

  // Example 3
  std::cout << slowKeyboard.enterTime("16:35") << std::endl;  // Output: 9

  // Example 4
  std::cout << slowKeyboard.enterTime("41:43") << std::endl;  // Output: 10

  // Example 5
  std::cout << slowKeyboard.enterTime("59:59") << std::endl;  // Output: 6

  // Example 6
  std::cout << slowKeyboard.enterTime("41:04") << std::endl;  // Output: 7

  // Example 7
  std::cout << slowKeyboard.enterTime("00:00") << std::endl;  // Output: 6

  // Example 8
  std::cout << slowKeyboard.enterTime("23:03") << std::endl;  // Output: 8

  // Example 9
  std::cout << slowKeyboard.enterTime("34:51") << std::endl;  // Output: 9

  // Example 10
  std::cout << slowKeyboard.enterTime("51:30") << std::endl;  // Output: 10

  // Example 11
  std::cout << slowKeyboard.enterTime("58:26") << std::endl;  // Output: 10

  // Example 12
  std::cout << slowKeyboard.enterTime("02:48") << std::endl;  // Output: 10

  return 0;
}

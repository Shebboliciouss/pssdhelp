#include <iostream>
#include <string>
using namespace std;

class SlowKeyboard{
public:
    int enterTime(std::string time ){
      //taking each string digits change to int by "-'0'" (ASCII 0=48, 1=49, ... so on)
      int min_tens = time[0] - '0';
      int min_ones = time[1] - '0';
      int sec_tens = time[3] - '0';
      int sec_ones = time[4] - '0';

      int timeTyping;
      int timeClockSeconds = 0;

      while(1){
         //typing 4 digits 
         timeTyping = 4;

         // checking if different from the next digit add 2 seconds
         if(min_tens == min_ones){
            timeTyping += 0;
         } else{
            timeTyping += 2;
         }
         if(sec_tens == min_ones){
            timeTyping += 0;
         } else{
            timeTyping += 2;
         }
         if(sec_tens == sec_ones){
            timeTyping += 0;
         } else{
            timeTyping += 2;
         }

         //terminate the while loop function
         if (timeTyping <= timeClockSeconds){
            return timeClockSeconds;
         }

         //increase the seconds
         sec_ones++;

         // if 00:09 --> 00:0(10) --> 00:10
         // change the ones in seconds to tens in seconds
         if(sec_ones == 10){
            sec_ones = 0;
            sec_tens++;
         }

         // if 00:59 --> 00:60 --> 01:00
         // change the tens in seconds to ones in minutes
         if(sec_tens == 6){
            sec_tens = 0;
            min_ones++;
         }

         // if 09:00 --> 0(10):00 --> 10:00
         // changing the ones in minutes to tens in minutes
         if(min_ones == 10){
            min_ones = 0;
            min_tens++;
         }

         // if 59:59 --> 60:00 --> 00:00
         // change the tens in minutes to 0 when reaches max
         if(min_tens == 6){
            min_tens = 0;
         }

         timeClockSeconds++; // a second has pass

      }

    }
};


#include <iostream>
#include <string>

class SlowKeyboard{
public:
    int enterTime(std::string s){

        int a = s[0]-'0' , b = s[1]-'0' , c = s[3]-'0' , d = s[4]-'0' , t = 0 , time ;
         while ( 1 ){
            time = 4 + (a==b?0:2) + (b==c?0:2) + (c==d?0:2) ;
            if ( time <= t ) return t ;  //terminate the loop function
            ++d ;
            if ( d == 10 ) 
              {
                 d = 0 ;
                 ++c ;
              }  
            if ( c == 6 )
              {
                 c = 0 ;
                 ++b ;
              }  
            if ( b == 10 )
              {
                 b = 0 ;
                 ++a ;
              }  
            if ( a == 6 )
              {
                 a = 0 ;                 
              }  
            ++t ;
         }  
    }
  
};

int main() {
    SlowKeyboard slowKeyboard;

    // Example 0
    std::cout << slowKeyboard.enterTime("59:56") << std::endl; // Output: 4

    // Example 1
    std::cout << slowKeyboard.enterTime("59:59") << std::endl; // Output: 6

    // Example 2
    std::cout << slowKeyboard.enterTime("33:12") << std::endl; // Output: 8

    // Example 3
    std::cout << slowKeyboard.enterTime("16:35") << std::endl; // Output: 9
    
    // Example 4
    std::cout << slowKeyboard.enterTime("41:43") << std::endl; // Output: 10

    // Example 5
    std::cout << slowKeyboard.enterTime("59:59") << std::endl; // Output: 6

    // Example 6
    std::cout << slowKeyboard.enterTime("41:04") << std::endl; // Output: 7

    // Example 7
    std::cout << slowKeyboard.enterTime("00:00") << std::endl; // Output: 6

    // Example 8
    std::cout << slowKeyboard.enterTime("23:03") << std::endl; // Output: 8

    // Example 9
    std::cout << slowKeyboard.enterTime("34:51") << std::endl; // Output: 9

    // Example 10
    std::cout << slowKeyboard.enterTime("51:30") << std::endl; // Output: 10

    // Example 11
    std::cout << slowKeyboard.enterTime("58:26") << std::endl; // Output: 10

    // Example 12
    std::cout << slowKeyboard.enterTime("02:48") << std::endl; // Output: 10
    
    return 0;
}




/*      // subtract string from index 0 and 2 index taken (0,1)
        // int targetMinutes = stoi(time.substr(0,2));
        // // subtract string from index 3 and 2 index taken (3,4)
        // int targetSeconds = stoi(time.substr(3,2));

        // int totalTime = 0;

        //totalTime += 2*(minute/10);  // Time to move to other keys, 50/10 = 5
        //totalTime += 1+(minute%10);  // Time to press the digit, taking the remainder, 59 % 10 = 9
        
*/
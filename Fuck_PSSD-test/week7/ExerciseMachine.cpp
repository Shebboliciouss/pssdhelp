#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class ExerciseMachine{
public:
    int getPercentages(string time) {
        istringstream streaming(time);
        int hrs, mins, secs;
        char colon;
        streaming >> hrs >> colon >> mins >> colon >> secs;
        int total_secs = hrs * 3600 + mins * 60 + secs;
        int count = 0;
        /*
        MUST DISPLAY WHOLE NUMBER PERCENTAGE NOT DECIMAL PERCENTAGE

        x/1800 * (100) = 1% (whole number and no remainder), --> x == 18 secs
        
        ** Can also be x*100 % totalsecs == 0 (x is 1 to tatal secs)
                ** can also be 1%(x) * 1800 % 100 == 0 (x is 1 to 99 percent)

        Example: 50 seconds --> 50/100 = 0.5 seconds to produce 1% (but cannot decimal seconds too)
        * 2% every 1 second, 10% every 5 second, 20% every 10sec --> 90% for 45 seconds, 92% == 46, ... 98% == 49secs, [x](100% == 50secs)[x] cannot output 100% so only 49 times

        */
       
        // cout << "1% PERcentage: " << (float)total_secs/100 << endl;
        // for(int i = 1; i < 100; i++){
        //     if(i * total_secs % 100 == 0){    
        //         count++;
        //     }
        // }
        
        return counter(1,count, total_secs);
    }

    int counter(int i, int count,const int total_secs){
        if(i == 100){
            return count;
        }
        if(i * total_secs % 100 == 0){    
                count++;
        }
        return counter(i+1, count, total_secs);
    }
};

int main() {
    ExerciseMachine machine;

    cout << machine.getPercentages("00:30:00") << endl; // Should print 99
    cout << machine.getPercentages("00:28:00") << endl; // Should print 19
    cout << machine.getPercentages("23:59:59") << endl; // Should print 0
    cout << machine.getPercentages("00:00:50") << endl; // Should print 49
    cout << machine.getPercentages("00:14:10") << endl; // Should print 49
    cout << machine.getPercentages("00:19:16") << endl; // Should print 3

    cout << machine.getPercentages("19:43:36") << endl; // Should print 3
    cout << machine.getPercentages("19:21:52") << endl; // Should print 3
    cout << machine.getPercentages("02:08:35") << endl; // Should print 4
    cout << machine.getPercentages("16:30:10") << endl; // Should print 9
    cout << machine.getPercentages("17:17:56") << endl; // Should print 3
    cout << machine.getPercentages("02:48:36") << endl; // Should print 3
    cout << machine.getPercentages("11:31:40") << endl; // Should print 99
    cout << machine.getPercentages("01:15:08") << endl; // Should print 3
    cout << machine.getPercentages("08:01:26") << endl; // Should print 1
    cout << machine.getPercentages("05:43:46") << endl; // Should print 1
    cout << machine.getPercentages("22:07:30") << endl; // Should print 49
    cout << machine.getPercentages("10:39:58") << endl; // Should print 1

    return 0;
}

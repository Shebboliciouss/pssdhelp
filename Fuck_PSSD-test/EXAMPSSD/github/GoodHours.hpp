//Received 100/100

#ifndef GOODHOURS_HPP
#define GOODHOURS_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GoodHours {

    public:

    int howMany(string beforeTime, string afterTime) {
            
        vector<int> before_time;
        vector<int> after_time;

        for(int i=0; i<beforeTime.size(); i++) {
            if(beforeTime[i] != ':') {
                before_time.push_back((beforeTime[i])-'0');
            }
        }
        for(int i=0; i<afterTime.size(); i++) {
            if(afterTime[i] != ':') {
                after_time.push_back((afterTime[i])-'0');
            }
        }

        int counter = 0;

        if(before_time == after_time) {
            if((before_time[0] == before_time[1]*before_time[2]*before_time[3]) || (before_time[0]*before_time[1] == before_time[2]*before_time[3]) || (before_time[0]*before_time[1]*before_time[2] == before_time[3])) {
                counter++;
            }
            return counter;
        }

        while (before_time != after_time) {
            if((before_time[0] == before_time[1]*before_time[2]*before_time[3]) || (before_time[0]*before_time[1] == before_time[2]*before_time[3]) || (before_time[0]*before_time[1]*before_time[2] == before_time[3])) {
                counter++;
            }

            if(before_time[0] == 2 && before_time[1] == 3 && before_time[2] == 5 && before_time[3] == 9) {
                before_time[0] = 0;
                before_time[1] = 0;
                before_time[2] = 0;
                before_time[3] = 0;
            } else if(before_time[0] == 0 && before_time[1] == 9 && before_time[2] == 5 && before_time[3] == 9) {
                before_time[0] = 1;
                before_time[1] = 0;
                before_time[2] = 0;
                before_time[3] = 0;
            } else if(before_time[0] == 1 && before_time[1] == 9 && before_time[2] == 5 && before_time[3] == 9) {
                before_time[0] = 2;
                before_time[1] = 0;
                before_time[2] = 0;
                before_time[3] = 0;
            } else if (before_time[0] == 1 && before_time[1] == 1 && before_time[2] == 5 && before_time[3] == 9) {
                before_time[0] = 1;
                before_time[1] = 2;
                before_time[2] = 0;
                before_time[3] = 0;
            } else if(before_time[2] == 5 && before_time[3] == 9) {
                before_time[1] = before_time[1] + 1;
                before_time[2] = 0;
                before_time[3] = 0;
            } else if(before_time[3] == 9) {
                before_time[2] = before_time[2] + 1;
                before_time[3] = 0;
            }
            else before_time[3] = before_time[3] + 1;

            
        }

        if((after_time[0] == after_time[1]*after_time[2]*after_time[3]) || (after_time[0]*after_time[1] == after_time[2]*after_time[3]) || (after_time[0]*after_time[1]*after_time[2] == after_time[3])) {
                counter++;
        }

        return counter;
    }

};

#endif
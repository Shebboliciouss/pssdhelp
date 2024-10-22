//Received 40/100

#ifndef ALTERNATE_COLORS_HPP
#define ALTERNATE_COLORS_HPP

#include <string>
#include <iostream>
using namespace std;

class AlternateColors {
    public:
        string getColor(long r, long g, long b, long k) { 

            int sum = r+g+b;
            int prod = sum*k;
            int div = prod/3;
            while(div>3) {
                div = div/3;
            }
            if(div == 1) {
                return "RED";
            } else if (div == 2) {
                return "GREEN";
            } else return "BLUE";            
        }
};

#endif
//Received 100/100

#ifndef FRACCOUNT_HPP
#define FRACCOUNT_HPP

#include <iostream>
using namespace std;

class FracCount {
    public:

        int gcd(int a, int b) { //got this from: https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
            if (b == 0)
                return a;
            return gcd(b, a % b);
        }

        int position(int numerator, int denominator) {
            int pos=0;
            for(int deno=2; deno<=1000; deno++) {
                for(int nume=1; nume<deno; nume++) {
                    if(gcd(nume,deno) == 1) {
                        pos++;
                    }
                    if(deno==denominator && nume==numerator) {
                        return pos;
                    }
                }
            }

        }
};

#endif
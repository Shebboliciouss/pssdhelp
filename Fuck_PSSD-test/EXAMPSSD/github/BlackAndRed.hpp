//Received 62/100

#ifndef BLACKANDRED_HPP
#define BLACKANDRED_HPP

#include <iostream>
#include <string>
using namespace std;

class BlackAndRed {
    public:
        int cut(string deck) {

            int bCount = 0;
            int rCount = 0;

            for(int i=0; i<deck.length(); i++) {

                if(deck[i] == 'B') {
                    bCount++;
                } else if (deck[i] == 'R') {
                    rCount++;
                    if (rCount > bCount) { 
                    return i+1;
                    }
                }

            }
        return 0;
        }
};

#endif
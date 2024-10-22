//Received 100/100

#ifndef BLACKANDWHITESOLITAIRE_HPP
#define BLACKANDWHITESOLITAIRE_HPP

#include <string>
#include <algorithm>
#include <iostream>

class BlackAndWhiteSolitaire {
    public:
        int minimumTurns(std::string cardFront) {
            
            int counter1 = 0;
            if(cardFront[0] == 'B') {
                for(int i=0; i<cardFront.size(); i++) {
                    if(i % 2 == 0 && cardFront[i] != 'B') {
                        counter1++;
                    } else if (i % 2 != 0 && cardFront[i] != 'W') {
                        counter1++;
                    }
                }
            } else if(cardFront[0] == 'W') {
                for(int i=0; i<cardFront.size(); i++) {
                    if(i % 2 == 0 && cardFront[i] != 'W') {
                        counter1++;
                    } else if (i % 2 != 0 && cardFront[i] != 'B') {
                        counter1++;
                    }
                }
            }

            if(cardFront[0] == 'B') {
                cardFront[0] = 'W';
            } else if (cardFront[0] == 'W') {
                cardFront[0] = 'B';
            }

            int counter2 = 1;
            if(cardFront[0] == 'B') {
                for(int i=0; i<cardFront.size(); i++) {
                    if(i % 2 == 0 && cardFront[i] != 'B') {
                        counter2++;
                    } else if (i % 2 != 0 && cardFront[i] != 'W') {
                        counter2++;
                    }
                }
            } else if(cardFront[0] == 'W') {
                for(int i=0; i<cardFront.size(); i++) {
                    if(i % 2 == 0 && cardFront[i] != 'W') {
                        counter2++;
                    } else if (i % 2 != 0 && cardFront[i] != 'B') {
                        counter2++;
                    }
                }
            }

            return std::min(counter1,counter2);
        }
};

#endif
//Received 100/100

#ifndef VERY_INTERESTING_MOVIE_HPP
#define VERY_INTERESTING_MOVIE_HPP

#include <string>
#include <vector>
using namespace std;

class VeryInterestingMovie {
    public:
        int maximumPupils(vector<string> seats) {
            int counter = 0;
            for(int row=0; row<seats.size(); row++) {
                for(int seat=0; seat<seats[row].size(); seat++) {
                    if(seats[row][0] == 'Y') {
                        counter++;
                        seats[row][0] = 0;
                    }
                    if(seats[row][seat] == 'Y' && seats[row][seat-1] != 0) {
                        counter++;
                        seats[row][seat] = 0;
                    }
                }
            }
            return counter;
        }
};

#endif
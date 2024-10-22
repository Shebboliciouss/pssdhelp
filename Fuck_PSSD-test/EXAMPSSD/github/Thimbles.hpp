//Received 100/100

#ifndef THIMBLES_HPP
#define THIMBLES_HPP

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Thimbles {
    public:
        int thimbleWithBall(vector<string> swaps) {

            int temp_index = 0;
            int current = 1;

            for(int r=0; r<swaps.size(); r++) {
                if(swaps[r][0] == '1') {
                    temp_index = r;
                    current = (swaps[r][2]) - '0';
                    break;
                } else if (swaps[r][2] == '1') {
                    temp_index = r;
                    current = (swaps[r][0]) - '0';
                    break;
                }
            }

            if(swaps.size()<2) {
                return current;
            }

            if(temp_index == swaps.size()) { 
                return current;
            }

            for(int r=temp_index+1; r<swaps.size(); r++) {
                if(((swaps[r][0])-'0') == current) {
                    current = (swaps[r][2]) - '0';
                } else if(((swaps[r][2])-'0') == current) {
                    current = (swaps[r][0]) - '0';
                }
            }

        return current;
        }
};

#endif
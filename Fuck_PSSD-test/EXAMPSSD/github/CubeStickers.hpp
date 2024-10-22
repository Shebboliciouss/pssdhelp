//Received 100/100

#ifndef CUBESTICKERS_HPP
#define CUBESTICKERS_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class CubeStickers {
    public:
        string isPossible(vector<string> sticker) {

            unordered_map<string,int> colors;

            for(int i=0; i<sticker.size(); i++) {
                colors[sticker[i]]++;
            }

            int sum = 0;
            if(colors.size()>=3) {
                for(auto it : colors) {
                    if(it.second > 2) {
                        sum = sum+2;
                    } else sum = sum + it.second;

                    if(sum>=6) {
                        return "YES";
                    }
                }
            }

        return "NO";
        }
};

#endif
//Received 100/100

#ifndef CATGAME_HPP
#define CATGAME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CatGame {
    public:
        int getNumber(vector<int> coordinates, int X) {
            vector<int> vec;
            for(int i=0; i<coordinates.size(); i++) {
                if(coordinates[i]<0) {
                    vec.push_back(coordinates[i]+X);
                } else if(coordinates[i]>=0) {
                    vec.push_back(coordinates[i]-X);
                }
            }
            int mini = *min_element(vec.begin(),vec.end());
            int maxi = *max_element(vec.begin(),vec.end());
            return abs(mini-maxi);
        }
};

#endif
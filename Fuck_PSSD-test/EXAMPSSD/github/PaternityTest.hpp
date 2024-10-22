//Received 100/100

#ifndef PATERNITYTEST_HPP
#define PATERNITYTEST_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PaternityTest {
    public:
        vector<int> possibleFathers(string child, string mother, vector<string> men) {
            int counter=0;
            vector<int> vec;
            for(int i=0; i<men.size(); i++) {
                counter=0;
                for(int j=0; j<men[i].size(); j++) {
                    if(men[i][j] == child[j]) {
                        counter++;
                    }
                    if((mother[j] != child[j]) && (men[i][j] != child[j])) {
                        if(counter >= (child.size()/2)) {
                            counter=0;
                        }
                        break;
                    }
                }
                if(counter >= (child.size()/2)) {
                    vec.push_back(i);
                }
            }
            return vec;
        }
};

#endif
//Received 100/100

#ifndef MOOINGCOWS_HPP
#define MOOINGCOWS_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class MooingCows {
    public:
        int dissatisfaction(vector<string>farmland) {

            if(farmland.size()==1 && farmland[0][0]=='C' && farmland[0][1]!='C') {
                return 0;
            }

            vector<int> dissatisfaction;

            for(int n=0; n<farmland.size(); n++) {
                
                for(int m=0; m<farmland[n].size(); m++) {
                    
                    if(farmland[n][m]=='C') {
                        int sum=0;
                        for(int i=0; i<farmland.size(); i++) {
                            for(int j=0; j<farmland[i].size(); j++) {
                                if(farmland[i][j]=='C') {
                                    sum = sum+(((n-i)*(n-i))+((m-j)*(m-j)));
                                }
                            }
                        }
                        dissatisfaction.push_back(sum);
                    }

                }
            }

            sort(dissatisfaction.begin(),dissatisfaction.end());

        return dissatisfaction[0];
        }
};

#endif
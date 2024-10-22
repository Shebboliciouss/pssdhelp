//Received 100/100

#ifndef CLUBADMISSION_HPP
#define CLUBADMISSION_HPP

#include <bits/stdc++.h>
using namespace std;

class ClubAdmission {
    public:
        int bestSum(vector<int> card) {

            vector<int> sums;
            vector<int> temp;

            for(int i=0; i<card.size(); i++) {
                int take=0;
                temp = card;
                take = temp[i];
                if(take>9 && take<90) {
                    while((take+10)<100) {
                        take = take+10;
                    }
                } else if (take<10) {
                    while((take+1)<10) {
                        take = take+1;
                    }
                } else {
                    while((take+1)<100) {
                        take = take+1;
                    }
                }
                temp[i] = take;
                int temp_sum=0;
                for(int j=0; j<card.size(); j++) {
                    temp_sum = temp_sum + temp[j];
                }
                sums.push_back(temp_sum);
            }

            int maxi = *max_element(sums.begin(),sums.end());

        return maxi;
        }
};

#endif
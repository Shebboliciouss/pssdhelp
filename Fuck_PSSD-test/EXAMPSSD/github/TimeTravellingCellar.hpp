//Received 100/100

#ifndef TIMETRAVELLINGCELLAR_HPP
#define TIMETRAVELLINGCELLAR_HPP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TimeTravellingCellar {
    public:
        int determineProfit(vector<int>profit, vector<int>decay) {

            int max_of_profit = *max_element(profit.begin(),profit.end());
            int min_of_decay = *min_element(decay.begin(),decay.end());

            int max_index = max_element(profit.begin(),profit.end())-profit.begin();
            int min_index = min_element(decay.begin(),decay.end())-decay.begin();

            if (max_index != min_index) {
                return  max_of_profit - min_of_decay;
            } else { 

                int secondMax = -1; 
                int secondMin = 10001; 
                for (int i = 0; i < profit.size(); i++) {
                    if (i != max_index) {
                        secondMax = max(secondMax, profit[i]); 
                    }

                    if (i != min_index) {
                        secondMin = min(secondMin, decay[i]); 
                    }
                }

            return max(max_of_profit - secondMin, secondMax - min_of_decay);
        }
    }
};

#endif
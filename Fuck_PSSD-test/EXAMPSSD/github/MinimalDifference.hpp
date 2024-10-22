//Received 96/100

#ifndef MINIMALDIFFERENCES_HPP
#define MINIMALDIFFERENCES_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinimalDifference {
    public:

        int digit_sum_calculator(int integer) {
            int digi_sum = 0;
            while(integer>0) {
                digi_sum = (integer%10) + digi_sum;
                integer = integer/10;
            }
            return digi_sum;
        }

        int findNumber(int A, int B, int C) {
            int digi_sum_of_C = digit_sum_calculator(C);
            for(int i=A; i<=B; i++) {
                if(digit_sum_calculator(i) == digi_sum_of_C) {
                    return i;
                }
            }
            vector<int> smallest_amongst;
            vector<int> smallest_amongst_index;
            for(int j=A; j<=B; j++) {
                smallest_amongst.push_back(digit_sum_calculator(j));
                smallest_amongst_index.push_back(j);
            }
            int mini = *min_element(smallest_amongst.begin(),smallest_amongst.end());
            int min_index = 0;
            int max = *max_element(smallest_amongst.begin(),smallest_amongst.end());
            int max_index = 0;
            for(int k=0; k<smallest_amongst.size(); k++) {
                if(smallest_amongst[k] == mini) {
                    min_index = k;
                } 
                if(smallest_amongst[k] == max) {
                    max_index = k;
                }
            }
            int final_min = 0;
            int final_max = 0;
            for(int l=0; l<smallest_amongst_index.size(); l++) {
                if(l == min_index) {
                    final_min = smallest_amongst_index[l];
                }
                if(l == max_index) {
                    final_max = smallest_amongst_index[l];
                }
            }
            if(abs(mini-digi_sum_of_C) < abs(max-digi_sum_of_C)) {
                return final_min;
            } else return final_max;
        }
};

#endif
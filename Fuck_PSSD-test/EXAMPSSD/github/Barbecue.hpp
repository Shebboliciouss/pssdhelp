//Received 75/100

#ifndef BARBECUE_HPP
#define BARBECUE_HPP

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Barbecue {
    public:
        int eliminate(int n, vector<int> voter, vector<int> excluded) {
            
            int excluded_values[n];
            int voter_values[n];
            for(int i=0; i<n; i++) {
                excluded_values[i] = 0;
                voter_values[i] = 0;
            }            

            for(int j=0; j<excluded.size(); j++) {
                excluded_values[excluded[j]]++;
                voter_values[voter[j]]++;
            }

            int first_max = -1;
            int second_max = -1;
            int first_max_index = 0;
            int second_max_index = 0;
            for(int k=0; k<n; k++) {
                if(excluded_values[k]>first_max) {
                    first_max = excluded_values[k];
                    first_max_index = k;
                }
            }

            for(int l=0; l<n; l++) {
                if(l != first_max_index) {
                    if(excluded_values[l] == first_max) {
                        second_max = excluded_values[l];
                        second_max_index = l;
                    }
                }
            }

           
            int voter1 = voter_values[first_max_index];
            int voter2 = voter_values[second_max_index];

            if(first_max != second_max) {
                return first_max_index;
            } else if (first_max == second_max) {
                if(voter1 == voter2) {
                    return min(first_max_index,second_max_index);
                } else return max(voter1,voter2);
            }

        }
};

#endif
//Received 100/100

#ifndef WORDGAME_HPP
#define WORDGAME_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class WordGame {
    public:

        int bestScore(string S) {

            vector<char> distinct_letters;

            for(int i=0; i<S.size(); i++) {
                if(!(find(distinct_letters.begin(),distinct_letters.end(),S[i]) != distinct_letters.end())) {
                    distinct_letters.push_back(S[i]);
                }
            }

            vector<int> occurrences;

            for(int j = 0; j<distinct_letters.size(); j++) {
                occurrences.push_back(count(S.begin(), S.end(), distinct_letters[j]));
            }

            int unmanipulated_sum = 0;
            for(int i=0; i<occurrences.size(); i++) {
                unmanipulated_sum  = unmanipulated_sum + (occurrences[i]*occurrences[i]);
            }

            int first_max = 0;
            int second_max = -1;
            int first_max_index = 0;
            int second_max_index = 0;

            first_max = *max_element(occurrences.begin(),occurrences.end());
            first_max_index = max_element(occurrences.begin(),occurrences.end()) - occurrences.begin();

            for(int i=0; i<occurrences.size(); i++) {
                if(i != first_max_index) {
                    second_max = max(second_max,occurrences[i]);
                }
            }

            for(int i=0; i<occurrences.size(); i++) {
                if(occurrences[i] == second_max) {
                    second_max_index = i;
                }
            }

            occurrences[first_max_index] = occurrences[first_max_index] + second_max;
            occurrences[second_max_index] = 0;

            int manipulated_sum = 0;
            for(int i=0; i<occurrences.size(); i++) {
                manipulated_sum  = manipulated_sum + (occurrences[i]*occurrences[i]);
            }

        return max(unmanipulated_sum,manipulated_sum);
        }

};

#endif
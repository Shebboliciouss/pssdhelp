//Received 100/100

#ifndef COLORFULRABBITS_HPP
#define COLORFULRABBITS_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class ColorfulRabbits {
    public:

        int getMinimum(vector<int> replies) {

            vector<double> values;

            for(int i=0; i<replies.size(); i++) {
                if(!(find(values.begin(),values.end(),replies[i]) != values.end())) {
                    values.push_back(replies[i]);
                }
            }

            vector<double> occurrences(values.size());

            for(int j=0; j<occurrences.size(); j++) {
                occurrences[j] = 0;
            }

            for(int l=0; l<values.size(); l++) {
                occurrences[l] = count(replies.begin(),replies.end(),values[l]);                
            }

            int sum = 0;
            for(int f=0; f<values.size(); f++) {
                double howManyTimes = 0;

                if(occurrences[f] == 1) {
                    sum = sum + (values[f] + 1);
                } 
                
                if (occurrences[f] > 1) {
                    howManyTimes = ceil(occurrences[f]/(values[f]+1));
                    sum = sum + (((values[f])+1) * howManyTimes);
                    cout<<sum<<endl;
                }
            }

            return sum;
        }
};

#endif
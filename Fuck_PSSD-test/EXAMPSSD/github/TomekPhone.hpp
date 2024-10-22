//Received 100/100

#ifndef TOMEKPHONE_HPP
#define TOMEKPHONE_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class TomekPhone {

    public:

        	int minKeystrokes(vector<int> frequencies, vector<int> keySizes) {

                if(frequencies.size() > accumulate(keySizes.begin(), keySizes.end(), 0)) {
                    return -1;
                }

                sort(frequencies.begin(),frequencies.end());
                reverse(frequencies.begin(),frequencies.end());
                
                vector<int> new_vector;
                int max_newvec_size = frequencies.size();             

                for(int i=0; i<max_newvec_size; i++) {
                    int pos = 0;
                    while(pos<keySizes.size()) {
                        if(keySizes[pos] > 0) {
                            new_vector.push_back(i+1);
                            keySizes[pos]--;
                        }
                        pos++;
                    }
                }

                int key_stokes = 0;
                for(int j=0; j<max_newvec_size; j++) {
                    key_stokes = key_stokes + (frequencies[j]*new_vector[j]);
                }

            return key_stokes;
            }

};

#endif
//Received 100/100

#ifndef FEWESTFACTORS_HPP
#define FEWESTFACTORS_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class FewestFactors {
    public:

        vector<int> permutations(vector<int> digits) {
            
            vector<int> perms;

            sort(digits.begin(),digits.end());

            do {
                int num=0;
                int diggiter = 0;
                for(int i=digits.size()-1; i>=0; i--) {
                    num = num + digits[diggiter]*pow(10,i);
                    diggiter++;
                }
                perms.push_back(num);
            } while(next_permutation(digits.begin(),digits.end()));

            return perms;
        }


        int number(vector<int> digits) {

            vector<int> everything = permutations(digits);
            vector<int> factors;

            for(int i=0; i<everything.size(); i++) {
                int counter=0;
                for(int j=1; j<=everything[i]; j++) {
                    if(everything[i] % j == 0) {
                        counter++;
                    }
                }
                factors.push_back(counter);
            }

           int min_el = *min_element(factors.begin(),factors.end());

            int index=0;
            for(int k=0; k<factors.size(); k++) {
                if(factors[k] == min_el) {
                    index = k;
                    break;
                }
            }

            return everything[index];
        }
};

#endif
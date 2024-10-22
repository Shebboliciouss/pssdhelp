//Received 100/100

#ifndef RUGSIZES_HPP
#define RUGSIZES_HPP

#include <iostream>
#include <vector>
using namespace std;

class RugSizes {

    public:

        int rugCount(int area) {

            if(area == 1) {
                return 1;
            }

            vector<int> factors;
            for(int i=1; i<=area; i++) {
                if(area % i == 0) {
                    factors.push_back(i);
                }
            }

            int pos=0;
            int counter=0;
            while(pos != factors.size()) {
                int element=pos;
                for(int k=pos; k<factors.size(); k++) {
                    if(factors[element] * factors[k] == area) {
                        if((factors[element]==factors[k]) ) {
                            counter++;
                        } else if (factors[element] % 2 != 0 || factors[k] % 2 != 0) {
                            counter++;
                        }
                        element++;
                    }
                }
                pos++;
            }

        return counter;
        }

};

#endif
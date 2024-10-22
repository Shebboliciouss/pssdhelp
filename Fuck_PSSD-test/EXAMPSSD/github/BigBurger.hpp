//Received 82/100

#ifndef BIGBURGER_HPP
#define BIGBURGER_HPP

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class BigBurger {
    public:
        int maxWait(vector<int> arrival, vector<int> service) {

            vector<int> finished(arrival.size());
            finished[0] = arrival[0] + service[0];
            int wait  = 0;

            for(int i=1; i<arrival.size(); i++) {
                finished[i] = finished[i-1] + service[i];
            }

            for(int j=1; j<arrival.size(); j++) {
                wait = max(wait,finished[j-1] - arrival[j]);
            }

        return wait;
        }
};

#endif
//Received 100/100

#ifndef TALILULU_COFFEE_HPP
#define TALILULU_COFFEE_HPP

#include <vector>
#include <algorithm>
using namespace std;

class TaliluluCoffee {
    public:
        int maxTip(vector<int> tips) {
            int counter_asc = 0;
            int counter_desc = 0;
            int temp = 0;
            sort(tips.begin(),tips.end());
            for(int i=0; i<tips.size(); i++) {
                temp = 0;
                temp = tips[i] - i;
                if(temp > 0) {
                    counter_asc = counter_asc + temp;
                }
            }
            reverse(tips.begin(),tips.end());
            for(int i=0; i<tips.size(); i++) {
                temp = 0;
                temp = tips[i] - i;
                if(temp > 0) {
                    counter_desc = counter_desc + temp;
                }
            }
            return max(counter_asc,counter_desc);
        }
};

#endif
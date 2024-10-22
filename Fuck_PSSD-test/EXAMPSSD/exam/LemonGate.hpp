#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LemonGate{
    public: 
        int maxNumber(vector<int> lemons){
            int length = lemons.size();
            vector<int> maxLemons(length);
            for (int i = 0; i < length; i++){
                maxLemons[i] = lemons[i];
            }
            
            maxLemons[1] = max(lemons[0], lemons[1]);

            for (int i = 1; i < length; i++){
                maxLemons[i] = max(maxLemons[i-1], maxLemons[i-2]+maxLemons[i]);
            }
            return maxLemons[length - 1];
        }
};

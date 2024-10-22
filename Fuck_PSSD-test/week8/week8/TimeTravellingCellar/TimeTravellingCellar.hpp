#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class TimeTravellingCellar {
public:
    int determineProfit(vector<int> profit, vector<int> decay) {
        // int ans = 0;
        // int p = profit.size();
        // int d = decay.size();
        // for (int i = 0; i < p; i++) {
        //     for (int j = 0; j < d; j++) {
        //         if (i != j) {
        //             ans = max(ans, profit[i] - decay[j]);
        //         }
        //     }
        // }
        // return ans;

        
        // vector<pair<int, int>> v;
        // int p = profit.size();
        // for (int i = 0; i < p; i++) {
        //     v.push_back(make_pair(profit[i], decay[i]));
        // }
        // sort(v.rbegin(), v.rend());
        // // for (auto it : v) {
        // //     cout << "(" << it.first << ", " << it.second << ")" << endl;
        // // }
        // int num = v[0].first;
        // auto index = min_element(decay.begin(), decay.end());
        // // if(index - decay.begin() != 0){
        // //     result = num - *index;
        // // } else{
        // //     decay.erase(index);
        // //     index = min_element(decay.begin(), decay.end());
        // // }
        // if(index - decay.begin() == 0){
        //     decay.erase(index);
        //     index = min_element(decay.begin(), decay.end());
        // }
        // return num - *index;


        int maxProfitIndex = max_element(profit.begin(), profit.end()) - profit.begin();
        int minDecayIndex = min_element(decay.begin(), decay.end()) - decay.begin();
        if(maxProfitIndex == minDecayIndex){
            int maxProfit = profit[maxProfitIndex];
            int minDecay = decay[minDecayIndex];
            vector<int>::iterator it = profit.begin()+maxProfitIndex;
            profit.erase(it);
            it = decay.begin()+minDecayIndex;
            decay.erase(it);
            int maxSecondProfit = *max_element(profit.begin(), profit.end());
            int minSecondDecay= *min_element(decay.begin(), decay.end());
            return max(maxProfit-minSecondDecay,maxSecondProfit-minDecay);
        }
        return profit[maxProfitIndex] - decay[minDecayIndex];
    }
};
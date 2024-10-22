#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class TimeTravellingCellar {
public:
    int determineProfit(vector<int> profit, vector<int> decay) {
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

int main() {
    TimeTravellingCellar cellar;

    vector<int> profit1 = {1,2,3};
    vector<int> decay1 = {3,1,2};
    cout << "Test case 0: " << cellar.determineProfit(profit1, decay1) << endl; // Expected output: 2

    vector<int> profit2 = {7116,8936};
    vector<int> decay2 = {9309,536};
    cout << "Test case 1: " << cellar.determineProfit(profit2, decay2) << endl; // Expected output: 6580

    vector<int> profit3 = {3,3,3};
    vector<int> decay3 = {1,1,1};
    cout << "Test case 2: " << cellar.determineProfit(profit3, decay3) << endl; // Expected output: 2

    vector<int> profit4 = {1000,500,250,125};
    vector<int> decay4 = {64,32,16,8};
    cout << "Test case 3: " << cellar.determineProfit(profit4, decay4) << endl; // Expected output: 992

    return 0;
}

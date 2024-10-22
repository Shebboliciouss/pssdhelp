#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class LemonGate {
public:
    int maxNumber(std::vector<int> lemons) {
        int n = lemons.size();
        std::vector<int> dp(n);

        dp[0] = lemons[0]; 
        dp[1] = std::max(lemons[0], lemons[1]); 

        for (int i = 2; i < n; ++i){   
            dp[i] = std::max(dp[i - 1], dp[i - 2] + lemons[i]);
        }
        return dp[n - 1];
    } 
};

int main() {
    LemonGate lemonGate;
    
    std::vector<int> lemons1 = {1, 2, 3};
    std::cout << lemonGate.maxNumber(lemons1) << std::endl; // Output: 4
    
    std::vector<int> lemons2 = {18, 5, 2, 13, 2, 9};
    std::cout << lemonGate.maxNumber(lemons2) << std::endl; // Output: 40
    
    std::vector<int> lemons3 = {1, 1, 10, 10, 1, 1};
    std::cout << lemonGate.maxNumber(lemons3) << std::endl; // Output: 12
    
    std::vector<int> lemons4 = {28, 65, 32, 7, 99, 14, 32};
    std::cout << lemonGate.maxNumber(lemons4) << std::endl; // Output: 196
    
    return 0;
}
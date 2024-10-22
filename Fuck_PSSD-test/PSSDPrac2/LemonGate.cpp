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
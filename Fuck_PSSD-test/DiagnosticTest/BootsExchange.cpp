#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BootsExchange{
public:
   int leastAmount(vector<int> left, vector<int> right){
        int exchange = 0;
        int n = left.size();

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int l = 0;
        int r = 0;
        while (l<n && r<n){
            if (left[l] == right[r]){
                l++;
                r++;
            } else if(left[l] < right[r]){
                l++;
                exchange++;
            } else{
                r++;
                exchange++;
            }
        }

        // for (int i = 0; i < n; i++){
        //     if (left[i] != right[i]){
        //         exchange++;
        //     }
        // }

        exchange += (n-l) + (n-r);
        return exchange/2;
   }
};

int main(){
    BootsExchange bootsExchange;

    // Example 0
    std::vector<int> left0 = {1, 3, 1};
    std::vector<int> right0 = {2, 1, 3};
    std::cout << bootsExchange.leastAmount(left0, right0) << std::endl; // Output: 1

    // Example 1
    std::vector<int> left1 = {1, 3};
    std::vector<int> right1 = {2, 2};
    std::cout << bootsExchange.leastAmount(left1, right1) << std::endl; // Output: 2

    // Example 2
    std::vector<int> left2 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> right2 = {2, 4, 6, 1, 3, 7, 5};
    std::cout << bootsExchange.leastAmount(left2, right2) << std::endl; // Output: 0

    // Example 2
    std::vector<int> left3 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> right3 = {2, 3, 3, 5, 6, 7, 8};
    std::cout << bootsExchange.leastAmount(left3, right3) << std::endl; // Output: 2

    return 0;
}

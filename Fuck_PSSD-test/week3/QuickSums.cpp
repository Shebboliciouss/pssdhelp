#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <limits.h>
using namespace std;

class QuickSums{
public:
    int generateSums(std::string input, int startIndex, int currentSum, int targetSum) {
    int n = input.size();
    if (startIndex == n) {
        if (currentSum == targetSum){
            return 0;
        } else{
            return INT_MAX;  
        }
    }

    int num = 0;
    int ans = INT_MAX;
    
    for (int i = startIndex; i < n; ++i) {
        num = num * 10 + (input[i] - '0');
        if (currentSum + num <= targetSum){
            int currentAddition = generateSums(input, i+1, currentSum+num, targetSum);
            if (currentAddition != INT_MAX){
                ans = min(ans, currentAddition+1);
            }
        }
        
    }
    
    return ans;
}

    int minSums(string numbers, int sum){
        int targetSum = sum;
        string number1 = numbers;
        int results = generateSums(numbers, 0, 0, targetSum); 
        if (results == INT_MAX ){
            return -1;
        } else{
            return results-1;
        }
    }








};


int main() {
    QuickSums qs;

    string numbers1 = "99999";
    int sum1 = 45;
    cout << "Minimum additions for " << numbers1 << " to get " << sum1 << ": " << qs.minSums(numbers1, sum1) << endl;

    string numbers2 = "1110";
    int sum2 = 3;
    cout << "Minimum additions for " << numbers2 << " to get " << sum2 << ": " << qs.minSums(numbers2, sum2) << endl;

    string numbers3 = "0123456789";
    int sum3 = 45;
    cout << "Minimum additions for " << numbers3 << " to get " << sum3 << ": " << qs.minSums(numbers3, sum3) << endl;

    string numbers4 = "99999";
    int sum4 = 100;
    cout << "Minimum additions for " << numbers4 << " to get " << sum4 << ": " << qs.minSums(numbers4, sum4) << endl;

    string numbers5 = "382834";
    int sum5 = 100;
    cout << "Minimum additions for " << numbers5 << " to get " << sum5 << ": " << qs.minSums(numbers5, sum5) << endl;

    string numbers6 = "9230560001";
    int sum6 = 71;
    cout << "Minimum additions for " << numbers6 << " to get " << sum6 << ": " << qs.minSums(numbers6, sum6) << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <limits>

// using namespace std;

// class QuickSums {
// public:
//     int minSums(string numbers, int sum) {
//         int target = sum;
//         int n = numbers.length();
//         int num = stoi(numbers);
//         if (num == target){
//             return 0;
//         }
//         // std::vector<int> dp;
//         // for (int i = 0; i < n; i++){
//         //     dp.push_back(stoi(numbers[i]));
//         // }

//         for (int i = 0; i < n; i++){
//             int number = 0;
//             for (int j = i ; j < n; j++){
//                 number = number * 10 + (numbers[j]-'0');
//                 cout << number << endl;
//                 if (num > sum){
//                     break;
//                 }  else if (num == sum){
//                     return num;
//                 }

//             }
//         }
//         return -1;
//         // int n = numbers.size();
//         // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, numeric_limits<int>::max()));
//         // dp[0][0] = 0;
//         // int n = dp.size();
//         //  for (int i = 0; i < n; i++){
//         //     for (int j = 0; j < dp[i].size(); j++){
//         //         cout << dp[i][j] << " ";
//         //     }    
//         //     cout << endl;
//         // }

//         // for (int i = 1; i <= n; ++i) {
//         //     int num = 0;
//         //     for (int j = i - 1; j >= 0; --j) {
//         //         num = num * 10 + (numbers[j] - '0');
//         //         if (num > sum) break;
                
//         //         for (int k = 0; k <= sum; ++k) {
//         //             if (dp[j][k] != numeric_limits<int>::max()) {
//         //                 dp[i][k + num] = min(dp[i][k + num], dp[j][k] + 1);
//         //             }
//         //         }
//         //     }
//         // }

//         // return (dp[n][sum] == numeric_limits<int>::max()) ? -1 : dp[n][sum];
        
//     }
// };


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class QuickSums{
public:

    std::vector<std::pair<long long, long long>> generateSums(const std::string& input, int startIndex, long currentSum, int plusCount, int targetSum) {
    std::vector<std::pair<long long, long long>> results;
    int n = input.length();
    if (startIndex == n) {
        if(currentSum == targetSum){
            results.push_back(std::make_pair(currentSum, plusCount));
            return results;
        }
        
    }
    
    for (int i = 1; i <= n - startIndex; i++) {
        std::string numStr = input.substr(startIndex, i);
        long long num = std::stoul(numStr);
        
        std::vector<std::pair<long long, long long>> subResults = generateSums(input, startIndex + i, currentSum + num, plusCount + 1, targetSum);
        results.insert(results.end(), subResults.begin(), subResults.end());
    }
    
    return results;
}

    int minSums(string numbers, int sum){
        int targetSum = sum;
        string number1 = numbers;
        int ans = -1;
        std::vector<std::pair<long long, long long>> results = generateSums(numbers, 0, 0, 0, targetSum);
        int n = results.size();
        for (int i = n-1; i >= 0; i--) {
            //cout<< results[i] << endl;
            if(results[i].first == sum){
                ans = (results[i].second);
                break;
            } else {
                ans = -1;
                continue;
            }
        
        }


        if (ans != -1){
            ans -= 1;
        }

        return ans;
    }

};

int main() {
    QuickSums qs;

    // string numbers1 = "99999";  //4
    // int sum1 = 45;
    // cout << "Minimum additions for " << numbers1 << " to get " << sum1 << ": " << qs.minSums(numbers1, sum1) << endl;

    // string numbers2 = "1110";  //3
    // int sum2 = 3;
    // cout << "Minimum additions for " << numbers2 << " to get " << sum2 << ": " << qs.minSums(numbers2, sum2) << endl;

    string numbers3 = "0123456789";  //8
    int sum3 = 45;
    cout << "Minimum additions for " << numbers3 << " to get " << sum3 << ": " << qs.minSums(numbers3, sum3) << endl;

    // string numbers4 = "99999";  //-1
    // int sum4 = 100;
    // cout << "Minimum additions for " << numbers4 << " to get " << sum4 << ": " << qs.minSums(numbers4, sum4) << endl;

    string numbers5 = "382834"; //2
    int sum5 = 100;
    cout << "Minimum additions for " << numbers5 << " to get " << sum5 << ": " << qs.minSums(numbers5, sum5) << endl;

    string numbers6 = "9230560001";  //4
    int sum6 = 71;  
    cout << "Minimum additions for " << numbers6 << " to get " << sum6 << ": " << qs.minSums(numbers6, sum6) << endl;

    string numbers7 = "0000000000";  //0
    int sum7 = 0;
    cout << "Minimum additions for " << numbers7 << " to get " << sum7 << ": " << qs.minSums(numbers7, sum7) << endl;

    // string numbers8 = "3769558148";   //-1
    // int sum8 = 99;
    // cout << "Minimum additions for " << numbers8 << " to get " << sum8 << ": " << qs.minSums(numbers8, sum8) << endl;

    string numbers9 = "0000000001";   //0
    int sum9 = 1;
    cout << "Minimum additions for " << numbers9 << " to get " << sum9 << ": " << qs.minSums(numbers9, sum9) << endl;

    string numbers10 = "1000000000";   //1
    int sum10 = 1;
    cout << "Minimum additions for " << numbers10 << " to get " << sum10 << ": " << qs.minSums(numbers10, sum10) << endl;

    return 0;
}
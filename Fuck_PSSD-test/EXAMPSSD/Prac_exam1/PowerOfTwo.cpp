/* // #include <iostream>
// #include <unordered_map>
// #include <cmath>

// using namespace std;

// long long returnNumber(long long N) {
//     // Create a map to keep track of the number of ways to represent each
//     value unordered_map<long long, long long> dp;

//     // Initialize with a single way to represent 0 (using no coins)
//     dp[0] = 1;

//     // Loop through possible coin values (powers of 2)
//     for (int k = 0; (1LL << k) <= N; ++k) {
//         long long coin = 1LL << k; // 2^k

//         // Make a copy of the current state of dp
//         unordered_map<long long, long long> new_dp(dp);

//         // For each coin value, update the number of ways to make various
//         totals for (auto& [value, count] : dp) {
//             long long new_value = value + coin;
//             if (new_value <= N) {
//                 // Two ways to represent new_value: either using the coin or
//                 not new_dp[new_value] += count;
//             }
//         }

//         // Don't forget that Sergey has exactly two coins of each value
//         dp = new_dp;
//         for (auto& [value, count] : new_dp) {
//             long long new_value = value + coin;
//             if (new_value <= N) {
//                 dp[new_value] += count;
//             }
//         }
//     }

//     // The answer is the number of ways to represent N
//     return dp[N];
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// class PowerOfTwo {
// public:
//     long returnNumber(long N) {
//         vector<long> dp(N + 1, 0);
//         dp[0] = 1;

//         for (int k = 0; (1LL << k) <= N; k++) {
//             for (long i = N; i >= 0; i--) {
//                 for (int j = 0; j <= 2; j++) {
//                     long value = j * (1LL << k);
//                     if (i - value >= 0) {
//                         dp[i] += dp[i - value];
//                     }
//                 }
//             }
//         }

//         long ways = 0;
//         for (long i = 1; i <= N; i++) {
//             if (dp[i] > 0) {
//                 ways++;
//             }
//         }

//         return ways;
//     }
// };

// int main() {
//     PowerOfTwo solver;

//     // Test cases
//     cout << solver.returnNumber(1) << endl;
//     cout << solver.returnNumber(6) << endl;
//     cout << solver.returnNumber(47) << endl;
//     cout << solver.returnNumber(256) << endl;
//     cout << solver.returnNumber(8489289) << endl;
//     cout << solver.returnNumber(1000000000) << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>

// #include <unordered_map>

// class PowerOfTwo {
// public:
//     long returnNumber(long N) {
//         std::unordered_map<long, long> dp;
//         return countWays(N, dp);
//     }

// private:
//     long countWays(long n, std::unordered_map<long, long>& dp) {
//         if (n == 0) {
//             return 1;
//         }
//         if (n < 0) {
//             return 0;
//         }
//         if (dp.find(n) != dp.end()) {
//             return dp[n];
//         }

//         long ways = 0;
//         for (long k = 0; (1LL << k) <= n; ++k) {
//             ways += countWays(n - (1LL << k), dp);
//         }

//         dp[n] = ways;
//         return ways;
//     }
// };

// #include <iostream>
// #include <vector>

// class PowerOfTwo {
// public:
//     long returnNumber(long N) {
//         std::vector<long long> dp(N + 1, 0);
//         dp[0] = 1;

//         for (int k = 0; (1LL << k) <= N; ++k) {
//             for (int i = (1LL << k); i <= N; ++i) {
//                 dp[i] += dp[i - (1LL << k)];
//             }
//         }

//         return dp[N];
//     }
// };

// int main() {
//     PowerOfTwo solution;

//     std::cout << solution.returnNumber(1) << std::endl;           // Expected
//     output: 1 std::cout << solution.returnNumber(6) << std::endl; // Expected
//     output: 3 std::cout << solution.returnNumber(47) << std::endl; //
//     Expected output: 2 std::cout << solution.returnNumber(256) << std::endl;
//     // Expected output: 9 std::cout << solution.returnNumber(8489289) <<
//     std::endl;     // Expected output: 6853 std::cout <<
//     solution.returnNumber(1000000000) << std::endl;  // Expected output:
//     73411

//     return 0;
// }

// int main() {
//     cout << returnNumber(1) << endl; // Should return 1
//     cout << returnNumber(6) << endl; // Should return 3
//     cout << returnNumber(47) << endl; // Should return 2
//     cout << returnNumber(256) << endl; // Should return 9
//     cout << returnNumber(8489289) << endl; // Should return 6853
//     cout << returnNumber(1000000000) << endl; // Should return 73411

//     return 0;
// }
*/
#include <iostream>
#include <vector>
using namespace std;
class PowerOfTwo {
 public:
  long returnNumber(long N) {
    vector<long> coins;
    long currentCoin = 1;
    long count = 0;
    // To generate the coins with the values that are powers of 2
    while (currentCoin <= N) {
      coins.push_back(currentCoin);
      currentCoin *= 2;
    }
    // To use the dynamic programming that to count with the number of ways that
    // to represent N
    vector<long> dp(N + 1, 0);
    dp[0] = 1;
    for (long coin : coins) {
      for (long i = coin; i <= N; i++) {
        dp[i] += dp[i - coin];
      }
    }
    // returns the count of the different representation of N
    return dp[N];
  }
};
// Main method for the class
int main() {
  PowerOfTwo p;
  // The Example usage
  cout << p.returnNumber(1) << endl;
  cout << p.returnNumber(6) << endl;
  cout << p.returnNumber(47) << endl;
  cout << p.returnNumber(256) << endl;
  cout << p.returnNumber(8489289) << endl;
  cout << p.returnNumber(1000000000) << endl;
  return 0;
}
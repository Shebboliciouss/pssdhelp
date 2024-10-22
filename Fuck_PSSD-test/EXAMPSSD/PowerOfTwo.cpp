#include <iostream>
#include <vector>

#include <unordered_map>

class PowerOfTwo {
public:
    long returnNumber(long N) {
        std::unordered_map<long, long> dp;
        return countWays(N, dp);
    }
    
private:
    long countWays(long n, std::unordered_map<long, long>& dp) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        
        long ways = 0;
        for (long k = 0; (1LL << k) <= n; ++k) {
            ways += countWays(n - (1LL << k), dp);
        }
        
        dp[n] = ways;
        return ways;
    }
};

#include <iostream>
#include <vector>

class PowerOfTwo {
public:
    long returnNumber(long N) {
        std::vector<long long> dp(N + 1, 0);
        dp[0] = 1;
        
        for (int k = 0; (1LL << k) <= N; ++k) {
            for (int i = (1LL << k); i <= N; ++i) {
                dp[i] += dp[i - (1LL << k)];
            }
        }
        
        return dp[N];
    }
};

int main() {
    PowerOfTwo solution;

    std::cout << solution.returnNumber(1) << std::endl;           // Expected output: 1
    std::cout << solution.returnNumber(6) << std::endl;           // Expected output: 3
    std::cout << solution.returnNumber(47) << std::endl;          // Expected output: 2
    std::cout << solution.returnNumber(256) << std::endl;         // Expected output: 9
    std::cout << solution.returnNumber(8489289) << std::endl;     // Expected output: 6853
    std::cout << solution.returnNumber(1000000000) << std::endl;  // Expected output: 73411

    return 0;
}
/*This code defines a PowerOfTwo class with a returnNumber method that calculates 
the number of different ways Sergey can represent the value N using the given coins. 
It uses a dynamic programming approach to build up the solutions for larger values of N 
based on the solutions for smaller values. The dp array is used to store the number of ways 
to represent each value from 0 to N. */






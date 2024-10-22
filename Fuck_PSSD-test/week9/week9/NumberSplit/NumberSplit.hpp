#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class NumberSplit {
public:
    int longestSequence(int start) {
        std::vector<int> dp(start + 1, 0);
        for (int i = 10; i <= start; ++i) {
            std::string s = std::to_string(i);
            int length = (s.size() - 1);
            int result = std::pow(2, length);
            //for (int j = 1; j < (1 << (s.size() - 1)); ++j) {
            for (int j = 1; j < result; ++j) {
                int product = 1, last = 0;
                for (unsigned int k = 0; k < s.size(); ++k) {
                    if (j & (1 << k)) {
                        product *= std::stoi(s.substr(last, k - last + 1));
                        last = k + 1;
                    }
                }
                product *= std::stoi(s.substr(last));
                dp[i] = std::max(dp[i], dp[product] + 1);
            }
        }
        return dp[start] + 1;
    }
};
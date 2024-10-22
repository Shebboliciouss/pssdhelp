#include <vector>
#include <string>
using namespace std;

class MatchNumbersEasy{
public:
    string calc (int index, int )
    string maxNumber(vector<int> matches, int n){
        int length = matches.size();
        string cost = "";
        int index = length-1;
        while(index >= 0){
            if(n >= matches[index]){
                n-= matches[index];
                cost += char(index + '0');
            }else{
                index--;
            }
        }
        return cost;
    }
};

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        map<int, string> memo;
        return dp(matches, n, memo);
    }

private:
    string dp(vector<int>& matches, int n, map<int, string>& memo) {
        if (memo.count(n)) {
            return memo[n];
        }
        string res = "";
        for (int i = 1; i < matches.size(); ++i) {
            if (n >= matches[i]) {
                string tmp = to_string(i) + dp(matches, n - matches[i], memo);
                if (tmp.length() > res.length() || (tmp.length() == res.length() && tmp > res)) {
                    res = tmp;
                }
            }
        }
        return memo[n] = res;
    }
};

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        int numDigits = matches.size();
        vector<string> dp(n + 1, "");
        for (int i = 0; i < numDigits; ++i) {
            if (matches[i] <= n) {
                dp[matches[i]] = max(dp[matches[i]], to_string(i));
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < numDigits; ++j) {
                if (matches[j] <= i && !dp[i - matches[j]].empty()) {
                    string temp = to_string(j) + dp[i - matches[j]];
                    dp[i] = max(dp[i], temp);
                }
            }
        }
        return dp[n].empty() ? "0" : dp[n];

        int numDigits = matches.size();
        vector<string> dp(n + 1, "");
        for (int i = 0; i < numDigits; i++){
            recursion()
        }
    }
};




int main() {
  MatchNumbersEasy n;
  string num = n.maxNumber({6,7,8},21);   //210
  for(char c:num){
      cout<< c;
  }
  cout << endl;

  string num1 = n.maxNumber({5, 23, 24}, 30);  // 20
  for (char c : num1) {
    cout << c;
  }
  cout << endl;

  string num2 = n.maxNumber({1,5,3,2},1);   //0
  for(char c:num2){
      cout<< c;
  }
  cout << endl;

  string num3 = n.maxNumber({1,1,1,1,1,1,1,1,1,1},50);//"99999999999999999999999999999999999999999999999999" 
  for(char c:num3){
      cout<< c;
  }
  cout << endl;

  string num4 = n.maxNumber({1, 5, 10}, 10);   //100000
  for(char c:num4){
      cout<< c;
  }
  cout << endl;

  return 0;
}

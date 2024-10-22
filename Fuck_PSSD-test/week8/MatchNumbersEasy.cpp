
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MatchNumbersEasy {
 public:
  string findLargestNumericString(vector<string>& dp, int n) {
    // if (stringVector.empty()) {
    //     return ""; // Return an empty string if the vector is empty
    // }
    // cout << "A";

    std::string largestNumericString = dp[0];  // Assume the first string is the largest initially

    // cout << "b";
    // dp.erase(dp.begin());

    // int index = 0;
    // cout << "c";
    // for (string str : dp) {
    //     // Compare each string in the vector
    //     if (str > largestNumericString) {
    //         //cout << "e";
    //         largestNumericString = str;
    //     }
    //     //cout << "f";
    //     ///stringVector.erase(stringVector.begin());
    // }

    // for(int i = 0; i < n+1; i++){
    //     //cout << "dp[" << i << "] = " << dp[i] << endl;
    //     if(dp[i] > largestNumericString){
    //         largestNumericString = dp[i];
    //     }
    //     //cout << "dp[" << i << "] = " << dp[i] << endl;
    //     //dp.erase(dp.begin());
    // }

    for (int i = 0; i < n + 1; i++) {
      // Compare the length of each string in the vector
      if (dp[i].length() > largestNumericString.length()) {
        largestNumericString = dp[i];
      }
      if (dp[i].length() == largestNumericString.length()) {
        // cout << "dp[" << i << "] = " << dp[i] << endl;
        for (int j = 0; j < dp[i].length(); j++) {
          // cout << "dp[" << i << "]["<<j<<"]= " << dp[i][j] << endl;
          // cout << "largestNumericString[" << j << "] = " <<
          // largestNumericString[j] << endl;
          if (dp[i][j] > largestNumericString[j]) {
            largestNumericString = dp[i];
            // cout << largestNumericString << endl;
            break;
          } else if (dp[i][j] == largestNumericString[j]) {
            continue;
          } else if (dp[i][j] < largestNumericString[j]) {
            break;
          }
        }
      }
    }
    // cout << "g";
    //  cout << "largestNumericString = ";
    //  for(char c:largestNumericString){
    //      cout<< c;
    //  }
    //  cout << endl;
    return largestNumericString;
  }

  string maxNumber(vector<int> matches, int n) {
    vector<string> dp(51, "");
    for (int i = 0; i < matches.size(); i++) {
      dp[matches[i]] = to_string(i);
      // cout << "dp[" << matches[i] << "] = " << to_string(i) << endl;
    }
    string res = "0";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < matches.size(); j++) {
        if (dp[i] != "") {
          //if(i <=n)
          //cout << "Stoi(dp[i]): " << i << endl;
          //cout << "matches[j]: " << matches[j] << endl;
          int new_index = i + matches[j];
          //cout << "new_index : " << new_index << endl;
          if (new_index > n) {
            continue;
          }
          //cout << "dp[" << i << "] = " << dp[i] << endl;
          //cout << "to_string(" << j << ") = " << to_string(j) << endl;
          string new_num = dp[i] + to_string(j);
          sort(new_num.rbegin(), new_num.rend());
          if (new_num[0] == '0') {
            new_num.erase(1);
          }
          //   for (char c : new_num) {
          //     cout << c;
          //   }
          // cout << endl;
          if (dp[new_index].length() < new_num.length()) {
            dp[new_index] = new_num;
          } else if (dp[new_index].length() == new_num.length()) {
            for (int i = 0; i < new_num.size(); i++) {
              if ((new_num[i] - '0') > (dp[new_index][i] - '0')) {
                dp[new_index] = new_num;
                break;
                //cout << "1....dp[" << new_index << "] = new_num--> " << new_num << endl;
              } else if ((new_num[i] - '0') == (dp[new_index][i] - '0')) {
                continue;
              } else if ((new_num[i] - '0') < (dp[new_index][i] - '0')) {
                break;
              }
            }
          }

          //   if ((dp[new_index] == "") || dp[new_index] < new_num) {
          //     dp[new_index] = new_num;
          //      cout << "dp[" << new_index << "] = new_num--> " << new_num <<
          //      endl;
          //   }
          // cout<< endl;
        }
      }
    }
    // for (int i =0; i <= n;i++){
    //     cout << "dp[" << i << "] = " << dp[i] << endl;
    // }
    string results = findLargestNumericString(dp, n);
    return results;
  }
};

int main() {
  MatchNumbersEasy n;
  string num = n.maxNumber({50, 50, 7, 8, 10, 50, 50, 11, 50, 50}, 48);  // 5000
  for (char c : num) {
    cout << c;
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

      string num3 =
      n.maxNumber({1,1,1,1,1,1,1,1,1,1},50);//"99999999999999999999999999999999999999999999999999"
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

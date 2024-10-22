#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MatchNumbersEasy {
 public:
  string findLargestNumericString(vector<string> stringVector) {
    // if (stringVector.empty()) {
    //     return ""; // Return an empty string if the vector is empty
    // }
    // cout << "A";
    std::string largestNumericString = stringVector[0]; // Assume the first string is the largest initially
    //cout << "b";
    stringVector.erase(stringVector.begin());
    // int index = 0;
    //cout << "c";
    for (string str : stringVector) {
        // Compare each string in the vector
        //cout << "d";
        if (str > largestNumericString) {
            //cout << "e";
            largestNumericString = str;
        }
        //cout << "f";
        stringVector.erase(stringVector.begin());
    }
    //cout << "g";
    // cout << "largestNumericString = ";
    // for(char c:largestNumericString){
    //     cout<< c;
    // }
    // cout << endl;
    return largestNumericString;
}


  string maxNumber(vector<int> matches, int n) {
    vector<string> dp(51, "");
    for (int i = 0; i < matches.size(); i++) {
      dp[matches[i]] = to_string(i);
      // cout << "dp[" << matches[i] << "] = " << to_string(i) << endl;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < matches.size(); j++) {
        if (dp[i] != "") {
          // cout << "Stoi(dp[i]): " << i << endl;
          // cout << "matches[j]: " << matches[j] << endl;
          int new_index = i + matches[j];
          // cout << "new_index : " << new_index << endl;
          if (new_index > n) {
            continue;
          }
          // cout << "dp[" << i << "] = " << dp[i] << endl;
          // cout << "to_string("<< j<< ") = " << to_string(j) << endl;
          string new_num = dp[i] + to_string(j);
          sort(new_num.rbegin(), new_num.rend());
          if (new_num[0] == '0') {
            new_num.erase(1);
          }
        //   for (char c : new_num) {
        //     cout << c;
        //   }
          // cout << endl;
          for (int i = 0; i < new_num.size(); i++) {
            if ((new_num[i] - '0') > (dp[new_index][i] - '0')) {
              dp[new_index] = new_num;
              // cout << "dp[" << new_index << "] = new_num--> " << new_num <<
              // endl;
            }
          }
          if ((dp[new_index] == "") || dp[new_index] < new_num) {
            dp[new_index] = new_num;
            // cout << "dp[" << new_index << "] = new_num--> " << new_num <<
            // endl;
          }
          // cout<< endl;
        }
      }
    }
    // for (int i =0; i <= n;i++){
    //     cout << "dp[" << i << "] = " << dp[i] << endl;
    // }
    string results = findLargestNumericString(dp);
    return results;
  }
};

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        vector<string> dp(51, "");
        for(int i = 0; i < matches.size(); i++){
            dp[matches[i]] = to_string(i);
            //cout << "dp[" << matches[i] << "] = " << to_string(i) << endl;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < matches.size();j++){
                if(dp[i] != ""){
                    //stoi changes string to integer
                    //cout << "Stoi(dp[i]): " << i << endl;
                    //cout << "matches[j]: " << matches[j] << endl;
                    int new_index = i + matches[j];
                    //cout << "new_index : " << new_index << endl;
                    if(new_index > n){
                        continue;
                    }
                    //cout << "dp[" << i << "] = " << dp[i] << endl;
                    //cout << "to_string("<< j<< ") = " << to_string(j) << endl;
                    string new_num = dp[i] + to_string(j);
                    sort(new_num.rbegin(), new_num.rend());
                    if(new_num[0] == '0'){
                        new_num.erase(1);
                    }
                    // for(char c:new_num){
                    //     cout<< c;
                    // }
                    // cout << endl;
                    for(int i = 0; i < new_num.size(); i++){
                        if((new_num[i]-'0') > (dp[new_index][i]-'0')){
                            dp[new_index] = new_num;
                        }
                    }
                    if((dp[new_index] == "") || dp[new_index] < new_num){
                        dp[new_index] = new_num;
                        //cout << "dp[" << new_index << "] = new_num--> " << new_num << endl;
                    }
                    
                    //cout<< endl;
                }
            }
        }
        // if(dp[n]== ""){
        //     for(int i = n; i >=0;i++){
        //         if(dp[i] != ""){
        //             return dp[n];
        //         }
        //     }
        // }
        return dp[n];            
    }
};



int main() {
  MatchNumbersEasy n;
//   string num = n.maxNumber({6,7,8},21);   //210
//   for(char c:num){
//       cout<< c;
//   }
//   cout << endl;

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

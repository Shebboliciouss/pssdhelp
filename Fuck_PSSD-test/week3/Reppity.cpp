#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Reppity{
    public:
        int longestRep(string input){
// 		// int N = input.size();
// 		// int s = N / 2;
// 		// for (; s >= 1; s--) {
// 		// 	for (int i = 0; i + 2 * s <= N; i++) { // [i, i+s-1]
// 		// 		for (int j = i+s; j + s <= N; j++) { // [j, j+s-1]
// 		// 			if (input.substr(i, s) == input.substr(j, s))
// 		// 				return s;
// 		// 		}
// 		// 	}
// 		// }
// 		// return 0;
            int n = input.length();
            int num[n+1][n+1];

            // Setting all elements in 'num' to 0
            memset(num, 0, sizeof(num));

            // To store length of repeating characters that appears at least twice
            int str_length = 0;
            //string res;
            //int index = 0;
            for (int i = 1; i <= n; i++){
                for (int j = i+1; j<=n; j++){
                    if (input[i-1]==input[j-1] && num[i-1][j-1] < (j-i)){                      
                        num[i][j] = num[i-1][j-1] +1;
                        if(num[i][j]>str_length){
                            str_length = num[i][j];
                        }
                    } else{
                       num[i][j] = 0; 
                    }
                }
            }

            for (int i = 0; i <= n; i++){
                for (int j = 0; j<=n; j++){
                    cout << num[i][j] << ", ";
                }
                cout<< endl;
            }

            // /*If we have non-empty result, then insert all
            // characters from first character to last
            // character of string*/
            // if (str_length > 0){
            //     for (int i = index - str_length + 1; i <= index; i++){
            //         res.push_back(input[i-1]);
            //     }
            // }
            // return res;

            return str_length;
        }
};

class Reppity {
public:
  int longestRep(string input) {
    int size = input.size();
    int re = size / 2;
    while (re > 0) {
      cout << "While (" << re << ">0)" << endl;
      int startPos = 0;
      
      while (startPos + re <= size) {
        cout << "While (startPos + re: " << startPos << "+" <<re<< "<= " <<size <<")" << endl;

        int pos = startPos;
        cout << "pos1: " << pos << endl;

        string str = input.substr(pos, re), str2;
        cout << "str: " << str << endl;

        pos += re;
        cout << "pos2: " << pos << endl;

        while (pos + re <= size && str != str2) {
          cout << "While (pos + re " << pos << "+" <<re<< "<= " <<size <<")" << endl;
 
          cout << "pos: " << pos<< " ,, re: " << re <<endl;
          //substr(start at, pull number of char)
          str2 = input.substr(pos, re);
          cout << "str2 : " << str2 << endl;
          ++pos;
        }


        if (str == str2){
            cout << "str: " << str<<", str2 : " << str2 << endl;
            return re;
        }  
        ++startPos;
      }
      --re;
    }
    return 0;
  }
};

int main() {
    Reppity solution;
    cout << solution.longestRep("aamaab") << endl;
    // cout << solution.longestRep("ABCDEXXXYYYZZZABCDEZZZYYYXXX") << endl;
    //cout << solution.longestRep("abcdabcdabcdabCD") << endl;
    // cout << solution.longestRep("abcdefghijklmnopqrstuvwxyabcdefghijklmnopqrstuvwxy") << endl;
    // cout << solution.longestRep("againANDagainANDagainANDagainANDagainANDagain") << endl;
    // cout << solution.longestRep("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX") << endl;
    
    return 0;
}
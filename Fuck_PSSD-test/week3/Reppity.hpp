#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Reppity{
    public:
        int longestRep(string input){
            int n = input.length();
            int num[n+1][n+1];

            // Setting all elements in 'num' to 0
            memset(num, 0, sizeof(num));

            // To store length of repeating characters that appears at least twice
            int str_length = 0;
            for (int i = 1; i <= n; i++){
                for (int j = i+1; j<=n; j++){
                    // (j-i) > num[i-1][j-1] to remove
                    // overlapping
                    if (input[i-1]==input[j-1] && num[i-1][j-1] < (j-i)){
                        num[i][j] = num[i-1][j-1] +1;
                        // updating maximum length of the substring
                        if(num[i][j]>str_length){
                            str_length = num[i][j];
                        }
                    } else{
                       num[i][j] = 0; 
                    }
                }
            }

            return str_length;
        }
};

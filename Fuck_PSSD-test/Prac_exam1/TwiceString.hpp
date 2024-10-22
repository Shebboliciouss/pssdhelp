#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class TwiceString{
    public:
    string getShortest(string s){
        int n = s.length();
        string str1 = "";
        // string str2 = s;
        // string res = str1 + str2;
        // // for(int i = 0; i < n; i++){
        // //     str.append(s[i]);
        // // }
        char* char_array = new char[2*n + 1];
        strcpy(char_array, s.c_str());
        strcpy(char_array[n], s.c_str());
        // int n2 = sizeof(char_array)/sizeof(*char_array);

        for (int i = 0; i < (2*n + 1); i++){
            if (char_array[i] == char_array[i+1]){
                continue;
            } else {
                str1.push_back(char_array[i]);
            }
        }
        return str1;

        // return count;
        // int n2 = res.length();
        
        // for (int i = 0; i < n2; i++){
        //     for (int j = i; j<n;j++){
        //         if (str.at[j]!=s.at[i]){
        //             continue;
        //         } else if (str.at[j]==str.at[j+1]){

        //         }
        //     }
        // }
        // // str.append("A");
        // // str.compare("ABCD")
        // return res;
    }
};

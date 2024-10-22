#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib> // for abs() function
#include <bits/stdc++.h> // for accumulate
using namespace std;

class ChangingString{
public:
    int distance(string A, string B, int K){
        vector<int> difference;
        int n = A.size();
        for (int i = 0 ; i < n; i++){
            int j = abs(B[i]-A[i]);
            difference.push_back(j);
        }
        sort(difference.rbegin(), difference.rend());

        for (int i = 0; i < K; i++){
            if (difference[i] == 0){
                difference[i] = 1;
            } else{
                difference[i] = 0;
            }
        }
        int sum = accumulate(difference.begin(), difference.end(), 0);
        return sum;
    }

};



int main() {
    ChangingString solver;
    
    std::cout << solver.distance("ab", "ba", 2) << std::endl;   //0
    std::cout << solver.distance("aa", "aa", 2) << std::endl;   //2
    std::cout << solver.distance("aaa", "baz", 1) << std::endl;     //1
    std::cout << solver.distance("fdfdfdfdfdsfabasd", "jhlakfjdklsakdjfk", 8) << std::endl;     //24
    std::cout << solver.distance("aa", "bb", 2) << std::endl;       //0

    return 0;
}
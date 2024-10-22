#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class DifferentStrings
{
public:
    // calculate the difference between string A and B starting at index i in string B.
    int get_difference(string A, string B, int i){
        int difference = 0;
        // iterate through characters of A
        for (unsigned int j = 0; j < A.length(); j++) {
            // if the characters at the corresponding position is different
            if (A[j] != B[i + j]) {
                // increase the difference
                difference++;
            }
        }
        return difference;
    }
    
    int minimize(string A, string B){
        int different_letters = B.length();
        // iterate through all possible starting positions for string A in B.
        for (unsigned int i = 0; i <= B.length() - A.length(); i++) {
            // calculate difference for the current alignment and update if it's smaller than the current min difference.
            different_letters = min(different_letters, get_difference(A, B, i));
        }
        return different_letters;
    }
};

int main() {
    DifferentStrings ds;
    string A = "koder";
    string B = "topcoder";
    int result = ds.minimize(A, B);
    cout << "The minimum possible difference is: " << result << endl;

    A = "hello";
    B = "xello";
    result = ds.minimize(A, B);
    cout << "The minimum possible difference is: " << result << endl;

    A = "abc";
    B = "topabcoder";
    result = ds.minimize(A, B);
    cout << "The minimum possible difference is: " << result << endl;

    A = "adaabc";
    B = "aababbc";
    result = ds.minimize(A, B);
    cout << "The minimum possible difference is: " << result << endl;

    A = "giorgi";
    B = "igroig";
    result = ds.minimize(A, B);
    cout << "The minimum possible difference is: " << result << endl;
    return 0;
}



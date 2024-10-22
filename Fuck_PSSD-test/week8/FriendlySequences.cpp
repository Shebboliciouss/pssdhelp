#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class FriendlySequences {
public:
    // string deleteRepetition(int num){
    //     string s = to_string(num);
    //     sort(s.begin(), s.end());
    //     s.erase(unique(s.begin(), s.end()),s.end());
    //     return s;
    // }

    bool friendly(int first, int second){
        string fir = to_string(first);
        string sec = to_string(second);
        for(auto str : fir){
            if(sec.find(str) == string::npos){
                return false;
            }
        }
        return true;
    }

    int count(vector<int> array) {
        int n = array.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (!(friendly(array[i], array[j]))){
                    break;
                } else{
                    count++;
                }
            }
        }
        return count;
    }
};



int main() {
    FriendlySequences solution;

    // Test cases
    vector<int> array1 = {112, 12, 21, 354, 534345, 345, 2221};
    cout << solution.count(array1) << endl;  // Output: 6

    vector<int> array2 = {10, 1100, 10101, 111, 1111, 11111, 11, 1, 111};
    cout << solution.count(array2) << endl;  // Output: 18

    vector<int> array3 = {0, 0, 0, 0};
    cout << solution.count(array3) << endl;  // Output: 6

    vector<int> array4 = {123456890, 213456890, 198654320};
    cout << solution.count(array4) << endl;  // Output: 3

    vector<int> array5 = {9};
    cout << solution.count(array5) << endl;  // Output: 0

    return 0;
}

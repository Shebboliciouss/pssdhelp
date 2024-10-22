// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <unordered_set>
// #include <vector>

// using namespace std;

// class FriendlySequences {
//  public:
//   string deleteRepetition(int num) {
//     // change integer to string
//     string s = to_string(num);

//     // sort the string in ascending order for easy checking
//     sort(s.begin(), s.end());

//     // erases all the duplivates numbers --> unique returns the ptr to the first
//     // duplicate number --> erase remove the starting ptr to ending ptr
//     s.erase(unique(s.begin(), s.end()), s.end());

//     return s;
//   }

//   int calc(int index, int len, vector<string>& str) {
//     // Base case : index reaches the end of the vector
//     if (index == len - 1) {
//       return 0;
//     }
//     int sum = 0;

//     // Check whether its neighbour contains the same digits
//     if (str[index] == str[index + 1]) {
//       // recursively call function to move on to the next index and +1 to sum as
//       // it would be a pair
//       sum = calc(index + 1, len, str) + 1;
//     }
//     return sum;
//   }

//   int count(vector<int>& array) {
//     int n = array.size();
//     vector<string> str;
//     for (int i = 0; i < n; i++) {
//       str.push_back(deleteRepetition(array[i]));
//     }
//     int length = str.size();
//     int count = 0;
//     // iterate though the vector and calculate the contiguous subsequence
//     for (int i = 0; i < length - 1; i++) {
//       count += calc(i, length, str);
//     }
//     return count;
//   }
// };

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
        for(auto str : sec){
            if(fir.find(str) == string::npos){
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
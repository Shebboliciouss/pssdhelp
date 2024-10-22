#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class HenrysKey {
public:
    int howMany(string S){
        int n = S.length();
        unordered_set<string> uniqueKeys;

        for (int i = 0; i < n; i++) {
            std::string key = S.substr(0, i) + S.substr(i + 1); // Erase character at index i
            //S.substr(0, 0) + S.substr(0 + 1)
            //        0      +      BA              (remove first letter 'A')
            //S.substr(0, 1) + S.substr(1 + 1)      
            //        A      +      A               (remove second letter 'B')
            //S.substr(0, 2) + S.substr(2 + 1)  
            //        AB      +      0              (remove third letter 'A')
            /*
            In the first solution, the line std::string key = S.substr(0, i) + S.substr(i + 1); creates a new string key by erasing the character at the index i from the original string S.

            Here's a breakdown of how it works:

            S.substr(0, i) extracts the substring of S starting from the beginning (index 0) up to (but not including) the character at index i. 
            This portion of the substring represents all characters in S before the one to be erased.

            S.substr(i + 1) extracts the substring of S starting from the character after the one at index i till the end of the string. 
            This portion of the substring represents all characters in S after the one to be erased.

            The + operator concatenates the two substrings obtained in steps 1 and 2, effectively creating the new string key with the character at index i removed.

            So, in essence, the line std::string key = S.substr(0, i) + S.substr(i + 1); 
            removes the character at index i from the original string S and stores the resulting string in key. 
            This operation is done for each index i in the loop, effectively creating all possible keys obtained by erasing a single character from S.
            */
            uniqueKeys.insert(key);
        }

        return uniqueKeys.size();
    }
};

int main(){
    HenrysKey henrysKey;
    string i = "ABA";
    cout << i.length() <<endl;
    cout << henrysKey.howMany("A") << endl;
    cout << henrysKey.howMany("ABA") << endl;
    cout << henrysKey.howMany("AABACCCCABAA") << endl;
    cout << henrysKey.howMany("AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ") << endl;
    cout << henrysKey.howMany("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ") << endl;
    return 0;
}
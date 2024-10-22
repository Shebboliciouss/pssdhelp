#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HenrysKey {
public:
    int howMany(string S){
        int n = S.length();
        int distinctKeys = 0;
        vector<string> seenKeys; // vector store seen keys

        for (int i = 0; i < n; i++) {
            std::string key = S;
            // delete 1 character from index number i
            key.erase(i,1);
            bool isUnique = true;
            for (const auto& seenKey : seenKeys) {
                if (seenKey == key) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                distinctKeys++;
                seenKeys.push_back(key); // Add the key to the vector of seen keys
            }
        }

        return distinctKeys;
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
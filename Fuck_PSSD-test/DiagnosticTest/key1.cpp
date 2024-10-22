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
            std::string key = S;
            // delete 1 character from index number i
            key.erase(i,1);
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
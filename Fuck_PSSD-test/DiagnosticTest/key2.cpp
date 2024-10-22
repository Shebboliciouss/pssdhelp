#include <iostream>
#include <string>
using namespace std;

class HenrysKey {
public:
    int howMany(string S){
        int n = S.length();
        int distinctKeys = 0;

        for (int i = 0; i < n; ++i) {
            std::string key = S;
            key.erase(i, 1); // Erase character at index i

            bool isDistinct = true;

            for (int j = 0; j < n - 1; ++j) {
                if (j != i && key == S.substr(0, j) + S.substr(j + 1)) {
                    isDistinct = false;
                    break;
                }
            }

            if (isDistinct) {
                distinctKeys++;
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
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class HenrysKey {
public:
    int howMany(string S){
        int count = 0;
        int n = S.length();
        char* char_array = new char[n + 1];
        strcpy(char_array, S.c_str());

        for (int i = 0; i < n; i++){
            if (char_array[i] == char_array[i+1]){
                count = count + 0;
            } else {
                count++;
            }
        
        }

        return count;

    }
};

int main(){
    HenrysKey henrysKey;
    cout << henrysKey.howMany("A") << endl;
    cout << henrysKey.howMany("ABA") << endl;
    cout << henrysKey.howMany("AABACCCCABAA") << endl;
    cout << henrysKey.howMany("AGAAGAHHHHFTQLLAPUURQQRRRUFJJSBSZVJZZZ") << endl;
    cout << henrysKey.howMany("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ") << endl;
    return 0;
}
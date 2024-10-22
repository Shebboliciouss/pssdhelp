#include <iostream>
#include <string>

using namespace std;

class MagicSpell{
    public:
    string fixTheSpell(string spell){
        string word = "";
        int n = spell.size();
        // get the A and Z from the String
        for (int i = 0; i < n; i++){
            if(spell[i]=='A'||spell[i]=='Z'){
                word += spell[i];
            }
        }

        //reverse(word.begin(), word.end());  //another way of reversing the string

        // or just iterate through the A and Z string in reverse
        int index = word.size()-1;
        for (int i = 0; i < n; i++){
            if(spell[i]=='A'||spell[i]=='Z'){
                // replace the A and Z characters with the reverse order
                spell[i] = word[index];
                index--;
            }
        }
        return spell;
    }
};

int main() {
    MagicSpell magicSpell;

    cout << magicSpell.fixTheSpell("AZ") << endl; // Output: "ZA"
    cout << magicSpell.fixTheSpell("ABACADA") << endl; // Output: "ABACADA"
    cout << magicSpell.fixTheSpell("AABZCADZA") << endl; // Output: "AZBACZDAA"
    cout << magicSpell.fixTheSpell("AZBASGHNAZAHBNVZZGGGAGGZAZ") << endl; // Output: "ZABZSGHNAZZHBNVAZGGGAGGAZA"

    return 0;
}
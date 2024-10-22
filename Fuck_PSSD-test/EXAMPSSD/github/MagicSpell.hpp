//Received 100/100

#ifndef MAGICSPELL_HPP
#define MAGICSPELL_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MagicSpell {

    public:
        
        string fixTheSpell(string spell) {

            vector<char> temp;

            for(int i=0; i<spell.length(); i++) {
                if(spell[i] == 'A' || spell[i] == 'Z') {
                    temp.push_back(spell[i]);
                    spell[i] = '_';
                }
            }

            reverse(temp.begin(),temp.end());
            
            int counter=0;
            for(int k=0; k<spell.size(); k++) {
                if(spell[k] == '_') {
                    spell[k] = temp[counter];
                    counter++;
                }
            }

        return spell;
        }

};

#endif
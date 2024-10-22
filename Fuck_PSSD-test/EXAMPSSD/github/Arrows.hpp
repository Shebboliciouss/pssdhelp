//Received 100/100

#ifndef ARROWS_HPP
#define ARROWS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Arrows {

    public:

        int longestArrow(string s) {
            
            int counter = 1;
            int j=0;
            vector<int> counterKeeper;

            int badCounter=0;
            int badCounter2=0;
            for(int k=0; k<s.length(); k++) {
                if(s[k] == '-' || s[k] == '=') {
                    badCounter++;
                } else if (s[k] == '<' || s[k] == '>') {
                    badCounter2++;
                }

                if(badCounter == s.length()) {
                    return -1;
                } else if (badCounter2 == s.length()) {
                    return 1;
                }
            }

            for(int i=0; i<s.length(); i++) {
                if(s[i] == '<' && s[i+1] == '-') {
                    counter++;
                    j=i+2;
                    while(s[j] == '-') {
                        counter++;
                        j++;
                    }
                    counterKeeper.push_back(counter);
                    counter = 1;
                    j=0;
                } 
                else if(s[i] == '<' && s[i+1] == '=') {
                    counter++;
                    j=i+2;
                    while(s[j] == '=') {
                        counter++;
                        j++;
                    }
                    counterKeeper.push_back(counter);
                    counter = 1;
                    j=0;
                }
                else if(s[i] == '>' && s[i-1] == '-') {
                    counter++;
                    j=i-2;
                    while(s[j] == '-') {
                        counter++;
                        j--;
                    }
                    counterKeeper.push_back(counter);
                    counter = 1;
                    j=0;
                }
                else if(s[i] == '>' && s[i-1] == '=') {
                    counter++;
                    j=i-2;
                    while(s[j] == '=') {
                        counter++;
                        j--;
                    }
                    counterKeeper.push_back(counter);
                    counter = 1;
                    j=0;
                } 
            }

        if(counterKeeper.empty() == true) {
            return 1;
        } else return *max_element(counterKeeper.begin(),counterKeeper.end());
        }      

};

#endif
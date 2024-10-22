#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class RunLengthEncoding{
public:
    string decode(string text){
        // store the count of the consecutive letters
        int length = 0;
        // store the decoded string 
        string word = "";

        // iterate each character in the encoded string 
        for (auto c : text){
            if (isdigit(c)){ // its a digit
                // *10 to count digits thats more than ones like 100 
                // " -'0' " to get the number value as ASCII val--> '0' = 48. '1' = 49
                length = length*10 + (c-'0');

                // check if the number is more than 50
                if (length > 50){
                    return "TOO LONG";
                } 
            } else{   // if its a leter

                // repeatedly adding the letter into the string by length times 
                if (length != 0){
                    for(int i = 0; i < length; i++){
                        word += c;
                    }
                } else{
                    // theres no number before the letter 
                    // then add the letter once into the string
                    word += c;
                }
                
                // check of length of the decoded string is more than 50
                int n = word.size();
                if(n > 50){
                    return "TOO LONG";
                }

                // reset the length for the next letter number
                length = 0;
            }
        }
        return word;
    }
};
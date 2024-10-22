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
        // istringstream streaming(text);
        // string word = "";
        // int number;
        // char character;
        // while(streaming){
        //     streaming >> number; 
        //     streaming >> character;
        //     for(int i = 0; i < number; i++){
        //         word += character; 
        //     }
        // }
        // return word;

        int length = 0;
        string word = "";
        for (auto c : text){
            if (isdigit(c)){
                // *10 to count digits thats more than ones like 100 
                // " -'0' " to get the number value as ASCII val--> '0' = 48. '1' = 49
                length = length*10 + (c-'0');
                if (length > 50){
                    return "TOO LONG";
                } 
            } else{
                if (length != 0){
                    for(int i = 0; i < length; i++){
                        word += c;
                    }
                    // int n = word.size();
                    // if(n > 50){
                    //     return "TOO LONG";
                    // }
                } else{
                    word += c;
                }
                int n = word.size();
                    if(n > 50){
                        return "TOO LONG";
                    }
                length = 0;

                /*
                Testing with input: 25A25BC
                Output expected: TOO LONG
                Output recieved: AAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBC

                FIRST FAILED TEST
                */





                // if(length == 0){
                //     length = 1;
                // }
                // for (int i = 0; i < length; i++){
                //     word += c;
                // }
                // length = 0;
                // int n = word.size();
                // if(n > 50){
                //     return "TOO LONG";
                // }
            }
        }
        return word;
    }
};
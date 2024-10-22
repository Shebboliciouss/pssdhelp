#include "Reverser.h"
    int Reverser::lengthDigit(int value){
        if(value/10 == 0){
            return 1;
        } else{
            return lengthDigit(value/10)+1;
        }
    }

    //This function takes in a non-negative int value and reverses the digits using recursion. 
    //The “reversed” int is then returned.
    int Reverser::reverseDigit(int value){
        //static int reverse = 0;
        if (value < 0){
            return -1;
        }else if (value == 0){
            return 0;
        } else if (value < 10){
            return value;
        }
        //else {  
            int last_num = value%10;
            int remainer = value/10;
            int length = lengthDigit(remainer);
        //}

        
        return reverseDigit(remainer) +  last_num * pow(10,length);
    }
    //The function takes in a std::string and returns the reversed string.
    string Reverser::reverseString(string characters){
        string reverseStr;
        //if(characters.length()==0) return "";
        if(characters.length() <= 0){
            return "ERROR";
        }else if (characters.length() == 1){
            return characters;
        }else {
            reverseStr = reverseString(characters.substr(1));
            reverseStr += characters[0];
        }
        return reverseStr;
    }



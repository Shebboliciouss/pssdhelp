//Received 100/100

#ifndef RUNLENGTHENCODING_HPP
#define RUNLENGTHENCODING_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class RunLengthEncoding {
    public:
        string decode(string text) {
            int pos = 0;
            int len_count=1;
            string substring = "";
            string new_string = "";
            string temp = "";
            int temp2 = 0;

            for(int i=0; i<text.length(); i++) {
                if(isalpha(text[i])) {
                    if(len_count>3) {
                        return "TOO LONG";
                    }
                    substring = text.substr(pos,len_count);
                    if(substring.size() == 1) {
                        new_string = new_string + substring;
                        len_count = 0;
                        substring = "";
                    } else 
                        {
                            temp = substring.back();
                            substring.erase(substring.end()-1);
                            temp2 = stoi(substring);
                            for(int j=0; j<temp2; j++) {
                                new_string = new_string + temp;
                            }    
                            temp = "";
                            temp2 = 0;
                            len_count = 0;
                            substring = "";
                        }
                        pos = i+1;
                }

                len_count++;
            }
            
            if(new_string.size()>50) {
                return "TOO LONG";
            } else return new_string;
        }
};

#endif
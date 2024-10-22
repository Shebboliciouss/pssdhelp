//Received 42/100

#ifndef DIFFERENTSTRINGS_HPP
#define DIFFERENTSTRINGS_HPP    

#include <iostream>
#include <string>
using namespace std;

class DifferentStrings {
    public:
        int minimize(string A, string B) {

            if(A.size() == B.size()) {
                int counter=0;
                for(int i=0; i<A.size(); i++) {
                    if(A[i] != B[i]) {
                        counter++;
                    }
                }
                return counter;
            }
            else if(B.find(A) != string::npos) {
                return 0;
            }
            else {
                int erase_counter=0;
                int temp = A.size();
                for(int j=0; j<temp; j++) {
                    if(!(B.find(A[j]) != string::npos)) {
                        erase_counter++;
                        A.erase(A.begin()+j);
                        temp = A.size();
                    }
                    if(B.find(A) != string::npos) {
                        return erase_counter;
                    }
                }
                return B.size()-temp;
            }   
        }
};

#endif
//Received 100/100

#ifndef DERIVATIVE_SEQUENCE_HPP
#define DERIVATIVE_SEQUENCE_HPP

#include <iostream> 
#include <vector>
using namespace std;

class DerivativeSequence {
    public:
        vector<int> derSeq(vector<int> a, int n) {
            if(n==0) {
                return a;
            } 
            
            for(int i=0; i<n; i++) {
                for(int j=0; j<a.size(); j++) {
                    int temp=0;
                    a[j] = a[j+1] - a[j];
                }
            }
            a.resize(a.size()-n);
            
            return a;
        }
};

#endif
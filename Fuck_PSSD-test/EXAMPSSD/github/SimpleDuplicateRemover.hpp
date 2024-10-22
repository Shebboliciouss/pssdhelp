//Received 100/100

#ifndef SIMPLEDUPLICATEREMOVER_HPP
#define SIMPLEDUPLICATEREMOVER_HPP

#include <algorithm>
#include <vector>
using namespace std;

class SimpleDuplicateRemover {
    public:
        vector<int> process(vector<int> sequence) {
            reverse(sequence.begin(),sequence.end());
            vector<int> newVec;
            for(int i=0; i<sequence.size(); i++) {
                if(!(find(newVec.begin(),newVec.end(),sequence[i]) != newVec.end())) {
                    newVec.push_back(sequence[i]);
                }
            }
            reverse(newVec.begin(),newVec.end());
            return newVec;
        }
};

#endif
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SimpleDuplicateRemover
{
public:
    vector<int> process(vector<int> sequence){
        // store the unique elements
        vector<int> results;

        int length = sequence.size()-1;
        
        // iterate the sequencer from right to left
        for (int i = length; i >= 0; i--){
            // check if the current element is in the results vector
            auto s = find(results.begin(), results.end(),sequence[i]);
            // if its not found in the vector then add the element to it
            if (s == results.end()){
                results.push_back(sequence[i]);
            }
        }
        // reverse to retain the order (rightmost number)
        reverse(results.begin(), results.end());
        return results; 
    }
};
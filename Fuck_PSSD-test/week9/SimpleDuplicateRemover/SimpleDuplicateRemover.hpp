#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SimpleDuplicateRemover
{
public:
    vector<int> process(vector<int> sequence){
        vector<int> results = sequence;
        results.resize(unique(results.begin(), results.end())-results.begin());
        return results;
    }
};
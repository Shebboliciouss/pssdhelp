#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class SimpleDuplicateRemover
{
public:
    vector<int> process(vector<int> sequence){
        // vector<int> results = sequence;
        // sort(results.begin(), results.end());
        // results.resize(unique(results.begin(), results.end())-results.begin());
        // vector<int> ans;
        // for (unsigned int i = 0; i < sequence.size(); i++){
        //     auto s = find(results.begin(), results.end(),sequence[i]);
        //     auto r = find(ans.begin(), ans.end(),sequence[i]);
        //     if((s != results.end()) && (r == ans.end())){
        //         ans.push_back(sequence[i]);
        //         if(ans.size() == results.size()){
        //             break;
        //         }
        //     }
        // }
        // return ans;
        vector<int> results;
        //unordered_map<int, int> map;
        int length = sequence.size()-1;

        for (int i = length; i >= 0; i--){
            auto s = find(results.begin(), results.end(),sequence[i]);
            if (s == results.end()){
                results.push_back(sequence[i]);
            }
            //map[sequence[i]]++;
        }
        reverse(results.begin(), results.end());
        return results;
        
    }
};



int main() {
    SimpleDuplicateRemover remover;

    // Test case 1
    std::vector<int> sequence1 = {1,5,5,1,6,1};
    std::vector<int> result1 = remover.process(sequence1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 2
    std::vector<int> sequence2 = {2,4,2,4,4};
    std::vector<int> result2 = remover.process(sequence2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 3
    std::vector<int> sequence3 = {6,6,6,6,6,6};
    std::vector<int> result3 = remover.process(sequence3);
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 4
    std::vector<int> sequence4 = {1,2,3,4,2,2,3};
    std::vector<int> result4 = remover.process(sequence4);
    for (int num : result4) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Test case 5
    std::vector<int> sequence5 = {100,100,100,99,99,99,100,100,100};
    std::vector<int> result5 = remover.process(sequence5);
    for (int num : result5) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

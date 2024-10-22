#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ImportantTasks
{
public:
    int maximalCost(vector<int> complexity, vector<int> computers){
        // int task = complexity.size();
        // int comp = computers.size();
        // sort(complexity.rbegin(), complexity.rend());
        // sort(computers.rbegin(), computers.rend());
        // int count = 0;
        // int i = 0;
        // int j = 0;
        // while(j < comp && i < task){
        //     if(complexity[i] <= computers[j]){
        //         i++;
        //         j++;
        //         count++;
        //     }else{
        //         i++;
        //     }
        // }
        sort(complexity.begin(), complexity.end());
        sort(computers.begin(), computers.end());
        int task = complexity.size();
        int comp = computers.size();
        int count = 0;
        for (int i = 0,j = 0; i < task && j < comp; i++,j++){
            (complexity[i] <= computers[j]) ? count++ : i-- ;
        }
        return count;
    }
};

int main(){
    ImportantTasks it;
    std::vector<int> complexity, computers;

    // Test case 0
    complexity = {1,2,3};
    computers = {2,2,2};
    std::cout << it.maximalCost(complexity, computers) << std::endl;  // Expected output: 2

    // Test case 1
    complexity = {1,2,3};
    computers = {3};
    std::cout << it.maximalCost(complexity, computers) << std::endl;  // Expected output: 1

    // Test case 2
    complexity = {3,5,1,7};
    computers = {9,4,1,1,1};
    std::cout << it.maximalCost(complexity, computers) << std::endl;  // Expected output: 3

    // Test case 3
    complexity = {5,2,7,8,6,4,2,10,2,3};
    computers = {4,1,3,6,2,10,11,1,1,3,4,2};
    std::cout << it.maximalCost(complexity, computers) << std::endl;  // Expected output: 8

    // Test case 4
    complexity = {100};
    computers = {100,100};
    std::cout << it.maximalCost(complexity, computers) << std::endl;  // Expected output: 1

    
    return 0;
}


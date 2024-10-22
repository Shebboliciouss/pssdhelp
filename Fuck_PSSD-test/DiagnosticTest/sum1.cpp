#include <vector>
#include <iostream>
using namespace std;

class SumOfPower{
public:
    int	findSum(vector<int>array){
        int n = array.size();;
        int sum = 0;
        for (int i = 0; i < n; i++){
            for(int k = i ; k < n; k++){
                for (int j = i; j <= k; j++)
                {
                    sum += array[j];
                }
            }
        }
        return sum;
    }
};

int main(){
    SumOfPower solver;

    std::vector<int> example1 = {1, 2};
    std::cout << "Example 1: " << solver.findSum(example1) << std::endl; // Output: 6

    std::vector<int> example2 = {1, 1, 1};
    std::cout << "Example 2: " << solver.findSum(example2) << std::endl; // Output: 10

    std::vector<int> example3 = {3, 14, 15, 92, 65};
    std::cout << "Example 3: " << solver.findSum(example3) << std::endl; // Output: 1323

    std::vector<int> example4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Example 4: " << solver.findSum(example4) << std::endl; // Output: 1210

    return 0;
}


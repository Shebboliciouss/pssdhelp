#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

class SumOfPower{
public:
    int	findSum(vector<int>array){
        int n = array.size();
        int total = 0;
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for(int k = 0 ; k+i <= n; k++){
                sum += accumulate(array.begin()+k, array.begin()+k+i, 0);
                total += sum;
            }
        }
        return total;

        // int sum = 0;
        //     int n = a.size();
        //     for(int i = 1; i <= n; i++){
        //         int s = 0;
        //         for(int j = 0; j+i <= n; j++)
        //             s += accumulate(a.begin()+j, a.begin()+j+i, 0);
        //         sum += s;
        //     }
        //     return sum;
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


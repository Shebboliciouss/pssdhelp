#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class MonstersValley2{
public:
int minimumPrice(vector<int> dread, vector<int> price){
    // int n = dread.size();
    // int scariness = dread[0];
    // int gold = price[0];

    // int scariness1 = dread[0];
    // int gold1 = price[0];

    // for (int i = 1 ; i < n; i++){
    //     if (dread[i] >= scariness){
    //         gold += price[i];
    //         scariness += dread[i];
    //     } 
    //     else {
    //         int min_bribe_price = gold;
    //         int min_scary = scariness;
    //         for(int j = 1; j <= i; j++){
    //             if(scariness+dread[j] >= dread[i]){
    //                 min_bribe_price = min(min_bribe_price, gold + price[j]);
    //                 min_scary = max(min_scary, scariness+dread[j]);
    //             }
    //         }
    //         scariness1 = min_scary;
    //         gold1 = min_bribe_price;
    //     }
    // }

    // cout << gold1 <<endl;
    // return gold; 

    // int n = dread.size();
    // int total_price = price[0];
    // int total_scariness = dread[0];

    // for (int i = 1; i < n; ++i) {
    //     if (dread[i] > total_scariness) {
    //         // If the current monster's scariness is greater than the total scariness,
    //         // bribe the monster and update the total scariness and total price.
    //         total_scariness += dread[i];
    //         total_price += price[i];
    //     } else {
    //         // If the current monster's scariness is not greater than the total scariness,
    //         // check if it's possible to avoid bribing.
    //         int remaining_scariness = total_scariness - dread[i];
    //         if (remaining_scariness >= dread[i]) {
    //             // If the remaining scariness is greater than or equal to the current monster's scariness,
    //             // avoid bribing and update the total scariness.
    //             total_scariness -= dread[i];
    //         } else {
    //             // If avoiding bribing is not possible, bribe the current monster to prevent an attack.
    //             total_scariness += dread[i];
    //             total_price += price[i];
    //         }
    //     }
    // }

    // return total_price;
    //map<pair<int, int>, long long> data;
    int n = dread.size();
    vector<long> totalDread(n, 0);
    for (int i = 0; i<n;i++){
        totalDread[i] = (long)dread[i];
    }
    return minPrice(0,0,totalDread,price);
}


int minPrice(long scariness, int index, vector<long>& totalDread, vector<int>& price){
    int n = totalDread.size();
    if (index >= n){
        return 0;
    } else{

        int gold = price[index] + minPrice(scariness+totalDread[index], index+1, totalDread, price);

        if(scariness >= totalDread[index]){  
            gold = min(gold, minPrice(scariness, index+1, totalDread, price));
            //return gold;
        } 
        return gold;
        // else{
        //     int gold = price[index] + minPrice(scariness+dread[index], index+1, dread, price);
        //     return gold;
        // }
    
    }
}

};


int main() {
    MonstersValley2 solver;

    // // Test case 0
    // vector<int> dread0 = {8, 5, 10, 17};
    // vector<int> price0 = {1, 1, 2, 3};
    // int result0 = solver.minimumPrice(dread0, price0);
    // cout << "Test Case 0: Minimum price to pass the valley is 2 == " << result0 << endl;

    // // Test case 1
    // vector<int> dread1 = {1, 2, 4, 1000000000};
    // vector<int> price1 = {1, 1, 1, 2};
    // int result1 = solver.minimumPrice(dread1, price1);
    // cout << "Test Case 1: Minimum price to pass the valley is 5 == " << result1 << endl;

    // // Test case 2
    // vector<int> dread2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
    // vector<int> price2 = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    // int result2 = solver.minimumPrice(dread2, price2);
    // cout << "Test Case 2: Minimum price to pass the valley is 40 == " << result2 << endl;

    // // Test case 3
    // vector<int> dread3 = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
    // vector<int> price3 = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
    // int result3 = solver.minimumPrice(dread3, price3);
    // cout << "Test Case 3: Minimum price to pass the valley is 5 == " << result3 << endl;

    // Test case 0
    vector<int> dread0 = {1999999991, 1999999992, 1999999993, 1999999994, 1999999995, 1999999996, 1999999997, 1999999998, 1999999999, 2000000000};
    vector<int> price0 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int result0 = solver.minimumPrice(dread0, price0);
    cout << "Test Case 0: Minimum price to pass the valley is 2 == " << result0 << endl;


    return 0;
}

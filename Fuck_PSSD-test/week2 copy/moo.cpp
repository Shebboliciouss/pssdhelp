#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

class MooingCows{
public:
    int dissatisfaction(vector<string> farmland){
        int row = farmland.size();
        int column = farmland[0].size();
        int cow = INT_MAX;
        for (int x = 0; x < row; x++){
            for (int y = 0; y < column; y++){
                // Letting one cow Moo 
                if (farmland[x][y]=='C'){
                    int dis = 0;
                    // Calculate the dissatisfaction for the other cows
                    for (int i = 0; i < row; i++){
                        for (int j = 0; j < column; j++){
                            if (farmland[i][j]=='C'){
                                // Square of the distance formula to calculate dissatisfaction
                                dis+=(pow((x-i),2)+pow((y-j),2));
                            }
                        }
                    }
                    // Getting the minimal total dissatisfaction
                    cow = min(cow, dis);
                }
                //cow = min(cow, dis);
            }
        }
        return cow;
    }
};

int main() {
    MooingCows mooingCows;

    // Test Case 0
    vector<string> farmland0 = {"C..",
                                ".C.",
                                ".C."};
    int result0 = mooingCows.dissatisfaction(farmland0);
    cout << "Test Case 0: " << result0 << endl; // Expected output: 3

    // Test Case 1
    vector<string> farmland1 = {"CCCC",
                                "CCCC",
                                "CCCC"};
    int result1 = mooingCows.dissatisfaction(farmland1);
    cout << "Test Case 1: " << result1 << endl; // Expected output: 26

    // Test Case 2
    vector<string> farmland2 = {"C"};
    int result2 = mooingCows.dissatisfaction(farmland2);
    cout << "Test Case 2: " << result2 << endl; // Expected output: 0

    // Test Case 3
    vector<string> farmland3 = {"CCC....",
                                "C......",
                                "....C.C",
                                ".C.CC..",
                                "C......"};
    int result3 = mooingCows.dissatisfaction(farmland3);
    cout << "Test Case 3: " << result3 << endl; // Expected output: 81

    return 0;
}








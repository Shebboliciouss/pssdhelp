#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class ElevatorLimit
{
public:
    vector<int> ans;
    vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit){
        vector<int> minmax = {};
        int length = enter.size();
        int min = INT_MAX;
        int max = INT_MIN;
        vector<int> enterNum;
        vector<int> exitNum;
        int currCapacity = 0;
        
        for (int j = 0; j < length; j++){
            if ((currCapacity > physicalLimit) || (exit[j]>physicalLimit)|| (enter[j]>physicalLimit)){
                return minmax;
            }
            currCapacity -= exit[j];
            exitNum.push_back(currCapacity);
            currCapacity += enter[j];
            enterNum.push_back(currCapacity);    
        }
        
        min = *min_element(exitNum.begin(), exitNum.end());
        max = *max_element(enterNum.begin(), enterNum.end());
        // if ((-min > max) || ((max-min) > physicalLimit)){
        //     return minmax;
        // }else if ((-min > physicalLimit) || ((physicalLimit-max) > physicalLimit)){
        //     return minmax;
        // }else if (max <= physicalLimit && max-min <= physicalLimit){
        //     minmax.push_back(-min);
        //     minmax.push_back(physicalLimit-max);
        // }
        int minimum = abs(min);
        int maximum = physicalLimit-max;
        if (maximum > physicalLimit) maximum = physicalLimit;

        if ((min == INT_MAX && max == INT_MIN) ||(maximum < minimum)){
            return minmax;
        }else if (max <= physicalLimit && max-min <= physicalLimit){
            minmax.push_back(minimum);
            minmax.push_back(maximum);
            
            
        }

        return minmax;
    }
};



int main() {
    ElevatorLimit elevator; // Create an instance of the ElevatorLimit class

    // Test cases
    // std::vector<int> enter1 = {295, 752, 84, 439, 607, 581 };
    // std::vector<int> exit1 = {558, 664, 644, 2, 564, 451};
    // int limit1 = 948;
    // std::vector<int> result1 = elevator.getRange(enter1, exit1, limit1);
    // std::cout << "Test Case 1: {" << result1[0] << ", " << result1[1] << "}" << std::endl;

    // std::vector<int> enter2 = {1, 0};
    // std::vector<int> exit2 = {0, 1};
    // int limit2 = 2;
    // std::vector<int> result2 = elevator.getRange(enter2, exit2, limit2);
    // std::cout << "Test Case 2: {" << result2[0] << ", " << result2[1] << "}" << std::endl;

    // std::vector<int> enter3 = {0, 1};
    // std::vector<int> exit3 = {1, 0};
    // int limit3 = 1;
    // std::vector<int> result3 = elevator.getRange(enter3, exit3, limit3);
    // std::cout << "Test Case 3: {" << result3[0] << ", " << result3[1] << "}" << std::endl;

    // std::vector<int> enter4 = {35, 125, 84, 47, 176, 71, 141, 46, 12, 174, 126, 14, 4, 58, 179, 161, 173, 148, 157, 175, 30, 53, 98, 99, 3, 100, 95, 174, 189, 23, 106, 101, 135, 70, 97, 156, 54, 156};
    // std::vector<int> exit4 = {199, 189, 136, 29, 8, 190, 108, 111, 46, 161, 174, 188, 49, 195, 66, 177, 147, 196, 30, 76, 178, 99, 104, 160, 114, 86, 63, 92, 66, 110, 82, 192, 104, 62, 71, 52, 76, 181};
    // int limit4 = 785;
    // std::vector<int> result4 = elevator.getRange(enter4, exit4, limit4);
    // std::cout << "Test Case 4: ";
    // if (result4.empty()) {
    //     std::cout << "{}" << std::endl;
    // } else {
    //     std::cout << "{" << result4[0] << ", " << result4[1] << "}" << std::endl;
    // }

    // std::vector<int> enter5 = {6, 85, 106, 1, 199, 76, 162, 141};
    // std::vector<int> exit5 = {38, 68, 62, 83, 170, 12, 61, 114};
    // int limit5 = 668;
    // std::vector<int> result5 = elevator.getRange(enter5, exit5, limit5);
    // std::cout << "Test Case 5: {" << result5[0] << ", " << result5[1] << "}" << std::endl;

    // std::vector<int> enter6 = {179, 135, 104, 90, 97, 186, 187, 47, 152, 100, 119, 28, 193, 11, 103, 100,
    //     179, 11, 80, 163, 50, 131, 103, 50, 142, 51, 112, 62, 69, 72, 88, 3, 162,
    //     93, 190, 85, 79, 86, 146, 71, 65, 131, 179, 119, 66, 111};
    // std::vector<int> exit6 = {134, 81, 178, 168, 86, 128, 1, 165, 62, 46, 188, 70, 104, 111, 3, 47, 144,
    //     69, 163, 21, 101, 126, 169, 84, 146, 165, 198, 1, 65, 181, 135, 99, 100,
    //     195, 171, 47, 16, 54, 79, 69, 6, 97, 154, 80, 151, 76};
    // int limit6 = 954;
    // std::vector<int> result6 = elevator.getRange(enter6, exit6, limit6);
    // std::cout << "Test Case 6: {" << result6[0] << ", " << result6[1] << "}" << std::endl;

    std::vector<int> enter7 = {295, 752, 84, 439, 607, 581 };
    std::vector<int> exit7 = {558, 664, 644, 2, 564, 451};
    int limit7 = 948;
    std::vector<int> result7 = elevator.getRange(enter7, exit7, limit7);
    std::cout << "Test Case 7: ";
    if (result7.empty()) {
        std::cout << "{}" << std::endl;
    } else {
        std::cout << "{" << result7[0] << ", " << result7[1] << "}" << std::endl;
    }

    return 0;
}


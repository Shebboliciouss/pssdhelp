#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

int main() {
    std::vector<std::string> stringVector = {"26 40 83", "49 60 57", "13 89 99"};

    // Initialize a vector to store the minimum values
    std::vector<int> minimumValues;

    for (size_t i = 0; i < stringVector.size(); ++i) {
        std::istringstream iss(stringVector[i]);
        int num;
        std::vector<int> row;

        while (iss >> num) {
            row.push_back(num);
        }

        // Find the minimum value in the row while ensuring it's different from the previous row
        int minVal = std::numeric_limits<int>::max();
        int prevMinVal = (i == 0) ? std::numeric_limits<int>::max() : minimumValues.back();

        for (int val : row) {
            if (val < minVal && val != prevMinVal) {
                minVal = val;
            }
        }

        minimumValues.push_back(minVal);
    }

    // Print the minimum values for demonstration
    for (int minValue : minimumValues) {
        std::cout << minValue << " ";
    }
    std::cout << std::endl;

    return 0;
}




#include <vector>
#include <iostream>
#include <algorithm>

class Snowstorm {
public:
    void blockedLength(std::vector<int> startPoints, std::vector<int> endPoints) {
        int n = startPoints.size();
        std::vector<std::pair<int, int>> segments;

        // Combine the start points and end points into pairs (segments)
        for (int i = 0; i < n; ++i) {
            segments.push_back(std::make_pair(startPoints[i], endPoints[i]));
        }

        for (int i = 0; i < n; i++){
                std::cout << segments[i].first << " , " << segments[i].second <<std::endl;     
        }

        std::cout << "-----------------------------------------------------------------------------------------" << std::endl;

        // Sort the segments based on their start points in ascending order
        std::sort(segments.begin(), segments.end());
        for (int i = 0; i < n; i++){
                std::cout << segments[i].first << " , " << segments[i].second <<std::endl;     
        }

        int totalLength = 0;
        int currentStart = segments[0].first;
        int currentEnd = segments[0].second;

        // Iterate through the sorted segments to find overlapping segments and accumulate their lengths
        for (int i = 1; i < n; i++) {
            if (segments[i].first <= currentEnd) {
                // Overlapping segment found, update the currentEnd to extend the current segment
                currentEnd = std::max(currentEnd, segments[i].second);
            } else {
                // Non-overlapping segment found, add the length of the current segment to the totalLength
                totalLength += (currentEnd - currentStart);
                // Start a new segment with the current segment
                currentStart = segments[i].first;
                currentEnd = segments[i].second;
            }
        }

        // Add the length of the last segment to the totalLength
        totalLength += (currentEnd - currentStart);

        //return totalLength;
    }
};

#include <iostream>

int main() {
    Snowstorm solver;
    std::vector<int> startPoints1 = {17, 85, 57};
    std::vector<int> endPoints1 = {33, 86, 84};
    solver.blockedLength(startPoints1, endPoints1);  

    // std::vector<int> startPoints1 = {17, 85, 57};
    // std::vector<int> endPoints1 = {33, 86, 84};
    // std::cout << "Example 1: " << solver.blockedLength(startPoints1, endPoints1) << std::endl; // Output: 44

    // std::vector<int> startPoints2 = {45, 100, 125, 10, 15, 35, 30, 9};
    // std::vector<int> endPoints2 = {46, 200, 175, 20, 25, 45, 40, 10};
    // std::cout << "Example 2: " << solver.blockedLength(startPoints2, endPoints2) << std::endl; // Output: 132

    // std::vector<int> startPoints3 = {4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554};
    // std::vector<int> endPoints3 = {7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423};
    // std::cout << "Example 3: " << solver.blockedLength(startPoints3, endPoints3) << std::endl; // Output: 9691

    // std::vector<int> startPoints4 = {4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720};
    // std::vector<int> endPoints4 = {4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928};
    // std::cout << "Example 4: " << solver.blockedLength(startPoints4, endPoints4) << std::endl; // Output: 9510

    // std::vector<int> startPoints5 = {51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168};
    // std::vector<int> endPoints5 = {1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017};
    // std::cout << "Example 5: " << solver.blockedLength(startPoints5, endPoints5) << std::endl; // Output: 9535

    // std::vector<int> startPoints6 = {8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060};
    // std::vector<int> endPoints6 = {9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180};
    // std::cout << "Example 6: " << solver.blockedLength(startPoints6, endPoints6) << std::endl; // Output: 9813

    return 0;
}


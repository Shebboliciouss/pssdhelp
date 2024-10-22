#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class RGBStreet {
 public:
  int estimateCost(vector<string> houses) {
    int n = houses.size();
    //vector<vector<int>> house(n, vector<int>(3, -1));
    vector<vector<int>> house;
    for (auto str : houses) {
      vector<int> row;
      istringstream iss(str);
      int number;
      while (iss >> number) {
        row.push_back(number);
      }
      house.push_back(row);
    }

    // cout << "Before Vector Update" << endl;
    // for (int i = 0; i < house.size(); i++) {
    //   for (int j = 0; j < house[i].size(); j++) cout << house[i][j] << " ";
    //   cout << endl;
    // }

    for (int i = 1; i < n; i++) {
      house[i].at(0) = min(house[i - 1][1], house[i - 1][2]) + house[i][0];
      house[i].at(1) = min(house[i - 1][0], house[i - 1][2]) + house[i][1];
      house[i].at(2) = min(house[i - 1][0], house[i - 1][1]) + house[i][2];
    }

    // cout << "After Vector Update" << endl;
    // for (int i = 0; i < house.size(); i++) {
    //   for (int j = 0; j < house[i].size(); j++) 
    //   std::cout << house[i][j] << " ";
    //   cout << endl;
    // }

    // // gets 1, 100, 100
    // stringstream str(houses[0]);
    // vector<int> cost(3, 0);
    // int index = 0;
    // // adding the cost of each colour in the colour vector
    // while (str >> cost[index++]);
    // house[0][0] = cost[0];
    // house[0][1] = cost[1];
    // house[0][2] = cost[2];

    // for (int i = 1; i  <n; ++i){
    //     // get the next element costs
    //     stringstream str(houses[i]);
    //     int j = 0;
    //     while (str >> cost[j++]);
    //     house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
    //     house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
    //     house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[2];

    // }

    return min({house[n - 1][0], house[n - 1][1], house[n - 1][2]});
  }
};

int main() {
  vector<vector<string>> testCases = {
      {"1 100 100", "100 1 100", "100 100 1"},
      {"1 100 100", "100 100 100", "1 100 100"},
      {"26 40 83", "49 60 57", "13 89 99"},
      {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"},
      {"71 39 44", "32 83 55", "51 37 63", "89 29 100",
       "83 58 11", "65 13 15", "47 25 29", "60 66 19"}
  };

  vector<int> expectedResults = {3, 102, 96, 208, 253};
  RGBStreet r;
  for (int i = 0; i < testCases.size(); ++i) {
      int result = r.estimateCost(testCases[i]);
      cout << "Test Case " << i << ": Expected = " << expectedResults[i] <<
      ", Actual = " << result << endl; cout << (result == expectedResults[i]
      ? "Pass" : "Fail") << endl; cout << endl;
  }

//   RGBStreet r;
//   cout << r.estimateCost({"1 100 100", "100 1 100", "100 100 1"}) << endl;
  return 0;
}

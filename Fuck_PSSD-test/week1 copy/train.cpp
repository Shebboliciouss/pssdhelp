#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class CircularLine {
 public:
  int longestTravel(vector<int> t) {
    int n = t.size();
    int total_length_rail = 0;
    int maxTravelTime = 0;

    for (int i = 0; i < n; i++){
        total_length_rail += t[i];
    }

    // Find the longest travel time between two consecutive stations
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++){
            int travelTime = 0;
            for (int k = i; k < j; k++){
                travelTime += t[k];
            }
            maxTravelTime = max(maxTravelTime, min(travelTime, total_length_rail-travelTime));
        }
    }
    return maxTravelTime;
  }
};


int main() {
  CircularLine circularLine;
  vector<int> t = {1, 4, 4, 1, 5};
  int result = circularLine.longestTravel(t);
  cout << "Longest travel time: " << result << endl;  // 7

  vector<int> a = {1, 1, 1, 1};
  int result1 = circularLine.longestTravel(a);
  cout << "Longest travel time: " << result1 << endl;  // 2

  vector<int> b = {1, 1, 1000};
  int result2 = circularLine.longestTravel(b);
  cout << "Longest travel time: " << result2 << endl;  // 2

  vector<int> c = {1, 1000, 1, 1000};
  int result3 = circularLine.longestTravel(c);
  cout << "Longest travel time: " << result3 << endl;  // 1001

  vector<int> d = {1, 1, 1, 1, 4};
  int result4 = circularLine.longestTravel(d);
  cout << "Longest travel time: " << resultetters
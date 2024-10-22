#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class GoodHours {
 public:
  int howMany(string beforeTime, string afterTime) {
    // Keep track how many time is GOOD
    int counter = 0;
    // Store the times which are GOOD 
    static unordered_set<string> times;
    // Indicate to stop iterating 
    bool timesUp = false;

    while (!timesUp) {
      int h1 = beforeTime[0] - '0';   // first digit of hours
      int h2 = beforeTime[1] - '0';   // second digit for hours
      int m1 = beforeTime[3] - '0';   // first digit of minutes
      int m2 = beforeTime[4] - '0';   // second digit for minutes

      // if the time is not inside the set then calculate the whether its GOOD
      if (times.find(beforeTime) == times.end()) {
        if (h1 == h2 * m1 * m2 || h1 * h2 == m1 * m2 || h1 * h2 * m1 == m2) {
          counter++;
          times.insert(beforeTime);   
        }
      } else {
        // If time is inside the set then its GOOD so increase counter
        counter++;
      }

      // if reaches the end time stop the iteration
      if (beforeTime == afterTime) {
        timesUp = true; 
      }

      // increase the time 
      m2++;

      if (m2 == 10) { 
        m2 = 0;
        m1++;
      }
     
      if (m1 == 6) {
        m1 = 0;
        h2++;
      }
      // hours 0-24, 9--> 10 , 19--> 20
      if ((h2 == 10) && (h1 == 0 || h1 == 1)) {
        h2 = 0;
        h1++;
      }
      if (h1 == 2 && h2 == 4) {
        h1 = 0;
        h2 = 0;
      }
      beforeTime = to_string(h1) + to_string(h2) + ":" + to_string(m1) + to_string(m2);
    }

    return counter;
  }
};

int main() {
  GoodHours gh;

  // Test case 0
  cout << gh.howMany("11:11", "11:11") << endl;  // 1

  // Test case 1
  cout << gh.howMany("00:56", "12:32") << endl;  // 164

  // Test case 2
  cout << gh.howMany("00:00", "00:59") << endl;  // 60

  // Test case 3
  cout << gh.howMany("10:10", "10:20") << endl;  // 2

  // Test case 4
  cout << gh.howMany("23:10", "01:23") << endl;  // 75

  // Additional test cases
  // Test case 5: Testing with the same hour and minute
  cout << gh.howMany("00:00", "23:59") << endl;  // 279

  // Test case 6: Testing with a time range within the same hour
  cout << gh.howMany("12:22", "12:21") << endl;  // 279

  // Test case 7: Testing with a time range that spans multiple hours
  cout << gh.howMany("00:01", "00:00") << endl;   // 279

  // Test case 8: Testing with a time range that spans from one day to the next
  cout << gh.howMany("23:00", "03:00") << endl;  // 95

  return 0;
}

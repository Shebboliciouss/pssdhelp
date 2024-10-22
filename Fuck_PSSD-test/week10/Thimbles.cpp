#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Thimbles {
public:
    int thimbleWithBall(vector<string> swaps) {
        // initialise the ball's position to the first thimble
        int ballpos = 1;
        for (auto swap : swaps) {
            int X = swap[0] - '0';
            int Y = swap[2] - '0';
            // if the thimble have a ball under it then swap 
            // which updates the ball's position to the other position 
            if (X == ballpos) {
                ballpos = Y;
            } else if (Y == ballpos) {
                ballpos = X;
            }
        }
        return ballpos;
    }
};

int main() {
  Thimbles th;

  // Test case 0
  cout << th.thimbleWithBall({"1-2", "3-1"}) << endl;  // 2

  // Test case 1
  cout << th.thimbleWithBall({"3-1", "2-3", "3-1", "3-2"}) << endl;  // 3

  // Test case 2
  cout << th.thimbleWithBall({"2-3", "1-3", "2-3", "2-1", "3-1"}) << endl;  // 3

  // Test case 3
  cout << th.thimbleWithBall({"1-2", "3-2", "1-2", "2-1", "2-1", "3-2", "1-3", "3-1", "1-2"}) << endl;  // 1

//   // Test case 4
//   cout << th.thimbleWithBall("23:10", "01:23") << endl;  // 75

//   // Additional test cases
//   // Test case 5: Testing with the same hour and minute
//   cout << th.thimbleWithBall("00:00", "23:59") << endl;  // 279

//   // Test case 6: Testing with a time range within the same hour
//   cout << th.thimbleWithBall("12:22", "12:21") << endl;  // 279

//   // Test case 7: Testing with a time range that spans multiple hours
//   cout << th.thimbleWithBall("00:01", "00:00") << endl;   // 279

//   // Test case 8: Testing with a time range that spans from one day to the next
//   cout << th.thimbleWithBall("23:00", "03:00") << endl;  // 95

  return 0;
}
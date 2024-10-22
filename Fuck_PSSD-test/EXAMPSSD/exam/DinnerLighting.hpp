#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DinnerLighting {
public:
  int countDarkSquares(int R, int C, vector<string> roomPlan) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (roomPlan[i][j] == 'O') {
          // go left 
          for (int k = j - 1; k >= 0; k--) { 
            if (roomPlan[i][k] == '.' || roomPlan[i][k] == '*') {
              roomPlan[i][k] = '*';
            } else {
              break; 
            }
          }

          // go right 
          for (int k = j + 1; k < C; k++) { 
            if (roomPlan[i][k]  == '.' || roomPlan[i][k] == '*') {
              roomPlan[i][k]  = '*';
            } else {
              break; 
            }
          }

          // go up
          for (int k = i - 1; k >= 0; k--) {
            if (roomPlan[k][j] == '.' || roomPlan[k][j] == '*') {
              roomPlan[k][j] = '*';
            } else {
              break; 
            }
          }

          // go down
          for (int k = i + 1; k < R; k++) { 
            if (roomPlan[k][j] == '.' || roomPlan[k][j] == '*') {
              roomPlan[k][j] = '*';
            } else {
              break; 
            }
          }
        }
      }
    }

    int black = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (roomPlan[i][j] == '.') {
          black++;
        }
      }
    }
  
    return black;
  }

};
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DinnerLighting{
public:
  int countDarkSquares(int R, int C, vector<string> roomPlan){
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        if (roomPlan.at(i).at(j) == 'O'){
          for (int k = i-1; k >= 0; k--){ // up
            if (roomPlan.at(k).at(j) == '.' | roomPlan.at(k).at(j) == '*'){
              roomPlan.at(k).at(j) = '*';
            } else{
              break;
            }
          }
          for (int k = i+1; k < R; k++){ // down
            if (roomPlan.at(k).at(j) == '.' | roomPlan.at(k).at(j) == '*'){
              roomPlan.at(k).at(j) = '*';
            } else{
              break;
            }
          }
          for (int k = j-1; k >= 0; k--){ // left
            if (roomPlan.at(i).at(k) == '.' | roomPlan.at(i).at(k) == '*'){
              roomPlan.at(i).at(k) = '*';
            } else{
              break;
            }
          }
          for (int k = j+1; k < C; k++){ // right
            if (roomPlan.at(i).at(k) == '.'  | roomPlan.at(i).at(k) == '*'){
              roomPlan.at(i).at(k) = '*';
            } else{
              break;
            }
          }
        }
      }
    }
    // for (int i = 0; i < R; i++){
    //   cout << roomPlan.at(i) << endl;
    // }
    return count(R,C,roomPlan);
  }
private:
  int count(int R, int C, vector<string> roomPlan){
    int res = 0;
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        if (roomPlan.at(i).at(j) == '.'){
          res++;
        }
      }
    }
    return res;
  }
};

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DinnerLighting {
public:
  int countDarkSquares(int R, int C, vector<string> roomPlan) {
    // This method takes three arguments:
    // 1. R: The number of rows in the room plan.
    // 2. C: The number of columns in the room plan.
    // 3. roomPlan: A vector of strings representing the room plan.

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (roomPlan[i][j] == 'O') {
          // When an 'O' (light source) is found in the room plan, the code proceeds
          // to update the grid to mark dark squares.

          // First, it marks dark squares in the upward direction.
          for (int k = i - 1; k >= 0; k--) { // up
            if (roomPlan[k][j] == '.' || roomPlan[k][j] == '*') {
              roomPlan[k][j] = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }

          // Then, it marks dark squares in the downward direction.
          for (int k = i + 1; k < R; k++) { // down
            if (roomPlan[k][j] == '.' || roomPlan[k][j] == '*') {
              roomPlan[k][j] = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }

          // Next, it marks dark squares to the left of the light source.
          for (int k = j - 1; k >= 0; k--) { // left
            if (roomPlan[i][k] == '.' || roomPlan[i][k] == '*') {
              roomPlan[i][k] = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }

          // Finally, it marks dark squares to the right of the light source.
          for (int k = j + 1; k < C; k++) { // right
            if (roomPlan[i][k]  == '.' || roomPlan[i][k] == '*') {
              roomPlan[i][k]  = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }
        }
      }
    }
    
    // After processing the room plan to mark dark squares, the code calls the
    // private 'count' method to count the number of dark squares and returns the result.
    return count(R, C, roomPlan);
  }

private:
  int count(int R, int C, vector<string> roomPlan) {
    int res = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (roomPlan.at(i).at(j) == '.') {
          res++;
        }
      }
    }
    // This private method counts the number of dark squares by counting the number
    // of '.' characters in the room plan and returns the result.
    return res;
  }
};
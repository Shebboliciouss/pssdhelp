#include <iostream>
#include <vector>
#include <string>
using namespace std;
It represents a room with R rows and C columns, where each string in roomPlan corresponds 
to a row in the room. Each character in the strings can be ‘O’ (a light), ‘.’ (a dark square), 
or ‘*’ (a square lit by a light).

The method iterates over each square in the room. If it finds a light (‘O’), 
it lights up all the squares in the same row and column until it hits another light or the edge of the room. 
This is done by four separate loops that go up, down, left, and right from the light’s position.

After all lights have been processed, it calls the count method to count the number of dark squares remaining in the room.

Method count: This private method takes the same parameters as countDarkSquares and returns an integer. 
It iterates over each square in the room and increments a counter whenever it finds a dark square (‘.’). 
Finally, it returns this counter.

This code simulates the process of turning on lights in a room and then counts the number of squares that remain dark. 
It assumes that each light illuminates all squares in its row and column unless blocked by another light.

However, there’s an issue with this code: it uses bitwise OR operator (|) instead of logical OR operator (||) in condition checks. 
The corrected condition checks should look like this:

if (roomPlan.at(k).at(j) == '.' || roomPlan.at(k).at(j) == '*'){
    ...
}

And similarly for other condition checks. The bitwise OR operator (|) performs a bitwise OR operation 
on binary representations of integers, while logical OR operator (||) performs a logical OR operation 
on boolean values. In this case, you want to check if either condition is true, so you should use logical OR operator (||).

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

class DinnerLighting {
public:
  int countDarkSquares(int R, int C, vector<string> roomPlan) {
    // This method takes three arguments:
    // 1. R: The number of rows in the room plan.
    // 2. C: The number of columns in the room plan.
    // 3. roomPlan: A vector of strings representing the room plan.

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (roomPlan.at(i).at(j) == 'O') {
          // When an 'O' (light source) is found in the room plan, the code proceeds
          // to update the grid to mark dark squares.

          // First, it marks dark squares in the upward direction.
          for (int k = i - 1; k >= 0; k--) { // up
            if (roomPlan.at(k).at(j) == '.' || roomPlan.at(k).at(j) == '*') {
              roomPlan.at(k).at(j) = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }

          // Then, it marks dark squares in the downward direction.
          for (int k = i + 1; k < R; k++) { // down
            if (roomPlan.at(k).at(j) == '.' || roomPlan.at(k).at(j) == '*') {
              roomPlan.at(k).at(j) = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }

          // Next, it marks dark squares to the left of the light source.
          for (int k = j - 1; k >= 0; k--) { // left
            if (roomPlan.at(i).at(k) == '.' || roomPlan.at(i).at(k) == '*') {
              roomPlan.at(i).at(k) = '*';
            } else {
              break; // If it encounters a non-empty space or another light source, stop.
            }
          }

          // Finally, it marks dark squares to the right of the light source.
          for (int k = j + 1; k < C; k++) { // right
            if (roomPlan.at(i).at(k) == '.' || roomPlan.at(i).at(k) == '*') {
              roomPlan.at(i).at(k) = '*';
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


Sure, I can help you modify the code. The main issue with the code is the use of the bitwise OR operator | 
instead of the logical OR operator || in the condition checks. Here’s the corrected version of your code:

class DinnerLighting{
public:
  int countDarkSquares(int R, int C, vector<string> roomPlan){
    for (int i = 0; i < R; i++){
      for (int j = 0; j < C; j++){
        if (roomPlan.at(i).at(j) == 'O'){
          for (int k = i-1; k >= 0; k--){ // up
            if (roomPlan.at(k).at(j) == '.' || roomPlan.at(k).at(j) == '*'){
              roomPlan.at(k).at(j) = '*';
            } else{
              break;
            }
          }
          for (int k = i+1; k < R; k++){ // down
            if (roomPlan.at(k).at(j) == '.' || roomPlan.at(k).at(j) == '*'){
              roomPlan.at(k).at(j) = '*';
            } else{
              break;
            }
          }
          for (int k = j-1; k >= 0; k--){ // left
            if (roomPlan.at(i).at(k) == '.' || roomPlan.at(i).at(k) == '*'){
              roomPlan.at(i).at(k) = '*';
            } else{
              break;
            }
          }
          for (int k = j+1; k < C; k++){ // right
            if (roomPlan.at(i).at(k) == '.'  || roomPlan.at(i).at(k) == '*'){
              roomPlan.at(i).at(k) = '*';
            } else{
              break;
            }
          }
        }
      }
    }
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

This code now correctly uses the logical OR operator || in the condition checks. 
This ensures that the conditions are evaluated correctly as boolean expressions. 
The rest of the code remains unchanged.

/*

This C++ code defines a class named DinnerLighting with two methods: countDarkSquares and count.

Here’s a detailed explanation of how this code works:

Method countDarkSquares: This method takes three parameters: two integers R and C, and a vector of strings roomPlan. It represents a room with R rows and C columns, where each string in roomPlan corresponds to a row in the room. Each character in the strings can be ‘O’ (a light), ‘.’ (a dark square), or ‘*’ (a square lit by a light).

The method iterates over each square in the room. If it finds a light (‘O’), it lights up all the squares in the same row and column until it hits another light or the edge of the room. This is done by four separate loops that go up, down, left, and right from the light’s position.

After all lights have been processed, it calls the count method to count the number of dark squares remaining in the room.

Method count: This private method takes the same parameters as countDarkSquares and returns an integer. It iterates over each square in the room and increments a counter whenever it finds a dark square (‘.’). Finally, it returns this counter.

This code simulates the process of turning on lights in a room and then counts the number of squares that remain dark. It assumes that each light illuminates all squares in its row and column unless blocked by another light.

*/
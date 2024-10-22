#include <vector>
#include <string>
#include <iostream>

using namespace std;

class BoardPieces{
public:
  int countSame(vector<string> board){
    int maxW = 0;
    int maxB = 0;
    int tempW = 0;
    int tempB = 0;
    for (int i = 0; i < board.at(0).size(); i++){
      tempW = 0;
      tempB = 0;
      for (int j = 0; j < board.size(); j++){
        if (j > 0){
          //if (board.at(j).at(i) == board.at(j-1).at(i)){
            if (board.at(j).at(i) == 'W'){
              tempW +=1;
              tempB = 0;
            } else if (board.at(j).at(i) == 'B'){
              tempB +=1;
              tempW = 0;
            }
          //}
          if (tempW > maxW){
            maxW = tempW;
          }
          if (tempB > maxB){
            maxB = tempB;
          }
        } else{
          if (board.at(j).at(i) == 'W'){
            tempW = 1;
          } else if (board.at(j).at(i) == 'B'){
            tempB = 1;
          }
          if (tempW > maxW){
            maxW = tempW;
          }
          if (tempB > maxB){
            maxB = tempB;
          }
        }
      }
    }
    if (maxB > maxW){
      return maxB;
    } else{
      return maxW;
    }
  }
};
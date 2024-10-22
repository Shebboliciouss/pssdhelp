#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CheatingGain{
public:
  int fakeH(vector<int> currentC, int budget, int fakeCost){
    sort(currentC.begin(),currentC.end(),greater<int>());
    int hval = getH(currentC);
    if (budget < fakeCost){
      return hval;
    }
    int fakes = budget/fakeCost;
    for (int i = hval/*+1*/; i < currentC.size(); i++){
      for (int j = 0; j < i; j++){
        if (currentC.at(j) < i){
          int diff = i-currentC.at(j);
          currentC.at(j) = i;
          fakes-=diff;
          if (fakes == 0 && j == i-1){
            return hval;
          } else if (fakes < 0){
            return hval-1;
          }
        }
      }
      hval++;
    }
    return hval;
  }
private:
  int getH(vector<int> currentC){ // for sorted array
    for (int i = 0; i < currentC.size(); i++){
      if (currentC.at(i)<i){
        return i-1;
      }
    }
    return 0;
  }
};
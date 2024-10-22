#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ClubAdmission{
public:
  int bestSum(vector<int> card){
    sort(card.begin(), card.end(), greater<int>());
    int og = getSum(card);
    int res = og;
    bool has2dig = false;
    for (int i = card.size()-1; i >= 0; i--){
      if (card.at(i) > 9){
        has2dig = true;
        if (card.at(i) == 99){
          res = res; // do nothing
        } else if (card.at(i) > 89){
          res += 99-card.at(i);
        } else {
          int tens = card.at(i)/10;
          // cout << tens << endl;
          res += (9-tens)*10;
        }
        break;
      }
    }
    if (card.back() < 10){
      og+=9-card.back();
      res = max(res,og);
    }
    return res;
  }
private:
  int getSum(vector<int> card){
    int res = 0;
    for (int i = 0; i < card.size(); i++){
      res+=card.at(i);
    }
    return res;
  }
};
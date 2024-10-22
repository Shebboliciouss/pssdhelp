#include <string>
#include <iostream>
using namespace std;

class TwiceString{
public:
  string getShortest(string S){
    for (int i = S.size()-1; i >= 0; i--){
      string concat = S.substr(i);
      string res = S + concat;
      int tot = 0;
      size_t found = res.find(S);
      if (found!=string::npos){
        // cout << "first occurrence found" << endl;
        tot++;
      }
      found=res.find(S,found+1);
      if (found!=string::npos){
        // cout << "second occurrence found" << endl;
        tot++;
      }
      if (tot == 2){
        return res;
      }
    }
  }
};
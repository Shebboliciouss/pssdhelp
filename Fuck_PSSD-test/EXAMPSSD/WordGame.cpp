#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class WordGame{
public:
  int bestScore(string s){
    if (s.size()<=2){
      return s.size()*s.size();
    }
    sort(s.begin(),s.end());
    // cout << s << endl;
    char temp = s.front();
    int oc = 1;
    vector<int> occurences;
    for (int i = 1; i < s.size(); i++){
      if (s.at(i) == temp && i < s.size()-1){
        oc++;
      } else if (s.at(i) == temp && i == s.size()-1){
        oc++;
        occurences.push_back(oc);
      } else if (i == s.size()-1){
        occurences.push_back(oc);
        occurences.push_back(1);
      } else{
        occurences.push_back(oc);
        temp = s.at(i);
        oc = 1;
      }
    }
    // for (int i = 0; i < occurences.size(); i++){
    //   cout << occurences.at(i) << " ";
    // }
    // cout << endl;
    if (occurences.size()==1){
      return occurences.at(0)*occurences.at(0);
    }
    sort(occurences.begin(),occurences.end(),greater<int>());
    // for (int i = 0; i < occurences.size(); i++){
    //   cout << occurences.at(i) << " ";
    // }
    // cout << endl;
    occurences.at(0) = occurences.at(0)+occurences.at(1);
    occurences.at(1) = 0;
    int res = 0;
    for (int i = 0; i < occurences.size(); i++){
      res+=occurences.at(i)*occurences.at(i);
    }
    // res++;
    return res;
  }
};
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cmath>
#include <cctype>
#include <climits>
#include <cstdio>
#include <utility>
using namespace std;
 
 
class WordSpaces {
  public:
  vector <int> find(string sentence, vector <string> words)
  {
    vector<int> ret;
    for(int c=0;c<words.size();c++)
    {
      int min=INT_MAX;
      for(int s=1;s<=sentence.size();s++)
      {
        for(int maxs=1;maxs<=sentence.size();maxs++)
        {
        for(int d=0;d<sentence.size();d++)
        {
          string temp="";
          for(int e=d;e<maxs;e+=s)
            temp+=sentence[e];
          cout<<temp<<endl;
          if(temp==words[c]&&d<min)
            min=d;
        }
        }
      }
      if(min==INT_MAX)
        min=-1;
      ret.push_back(min);
    }
    return ret;
  }  
};
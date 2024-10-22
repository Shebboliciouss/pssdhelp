#line 2 "CheatABit.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define REP(i,n) for(int i = 0; i < (n); ++i)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define sz size()

typedef pair<int,int> pi; typedef vector<int> vi; typedef vector<string> vs; 

int my;

int go(const vi& x)
{
  if(x.sz == 1) return 0;
  vi next;
  int add = 0;
  for(int i = 0; i < x.sz; i += 2)
  {
    if(x[i] == -1)
    {
      if(x[i+1] > my)
        add = 1;
      next.pb(-1);
    }
    else if(x[i+1] == -1)
    {
      if(x[i] > my)
        add = 1;
      next.pb(-1);
    }
    else
      next.pb(max(x[i], x[i+1]));
  }
  return go(next) + add;
}

struct CheatABit
{ 
  int enterCodes(vector <int> ratings, int yourRating) 
  { 
    int sol = 100;
    my = yourRating;
    REP(i,ratings.sz+1)
    {
      vi r = ratings;
      r.insert(r.begin()+i, -1);
      /*REP(i,r.sz)
        printf("%d ", r[i]);
      printf("\n");*/
      //???????   sol <?= go(r);
    }
    return sol;
  }   
 
}; 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <map>
#include <queue>
#include <set>
 
using namespace std;
 
#define FOR(i,n) for(int i=0; i<(n); i++)
#define pb push_back
typedef vector<int> VI;
 
int go(VI& r, int my) {
  if (r.size() == 1) return 0;
  VI rr;
  int res = 0;
  for(int i = 0; i < r.size(); i += 2) {
    int win = r[i] >? r[i+1], lose = r[i] <? r[i+1];
    if (lose == my) win = my, res++;
    rr.pb(win);
  }
  return res + go(rr, my);
}
 
struct CheatABit {
int enterCodes(vector <int> ratings, int yourRating) {
  VI r = ratings;
  int res = 10;
  FOR(i, ratings.size() + 1) {
    r = ratings;
    r.insert(r.begin() + i, yourRating);
    //res <?= go(r, yourRating);
  }
  return res;
}
};
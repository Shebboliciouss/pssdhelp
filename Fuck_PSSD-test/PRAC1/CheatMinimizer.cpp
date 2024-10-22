// #include <iostream>
// #include <vector>

// using namespace std;

// int minimalNumberOfCodes(vector<int>& ratings, int yourRating) {
//   if (ratings.empty()) {
//     return 0;
//   }

//   int n = ratings.size();

//   vector<int> cheats(n, 0);

//   for (int roundSize = 1; roundSize < n; roundSize *= 2) {
//     for (int i = 0; i < n; i += 2 * roundSize) {
//       int leftStart = i;

//       int leftEnd = min(i + roundSize, n);

//       int rightStart = leftEnd;

//       int rightEnd = min(i + 2 * roundSize, n);

//       int leftIndex = leftStart;

//       int rightIndex = rightStart;

//       int currentCheats = 0;

//       for (int j = i; j < rightEnd; j++) {
//         if (leftIndex < leftEnd &&
//             (rightIndex >= rightEnd ||
//              ratings[leftIndex] <= ratings[rightIndex])) {
//           ratings[j] = ratings[leftIndex];

//           leftIndex++;

//         } else {
//           ratings[j] = ratings[rightIndex];

//           rightIndex++;

//           currentCheats++;
//         }
//       }

//       for (int j = i; j < rightEnd; j++) {
//         cheats[j] += currentCheats;
//       }
//     }
//   }

//   return cheats[0];
// }

// int main() {
//   vector<int> ratings = {100, 1, 99, 2, 98, 3, 97, 4, 96, 5, 95, 6, 94, 7, 93};

//   int yourRating = 50;

//   int result = minimalNumberOfCodes(ratings, yourRating);

//   cout << result << endl;  // Output: 1

//   return 0;
// }

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class CheatMinimizer {
public:
    int minimize(vector<int> ratings, int yourRating) {
        int n = ratings.size();
        vector<pair<int, bool>> players;  // Pair of (rating, isYou)
        
        // Add yourself to the list of players
        players.push_back({yourRating, true});
        
        // Add other players to the list
        for (int i = 0; i < n; i++) {
            players.push_back({ratings[i], false});
        }
        
        sort(players.begin(), players.end(), greater<pair<int, bool>>());
        
        int cheatCount = 0;
        while (players.size() > 1) {
            vector<pair<int, bool>> winners;
            
            for (int i = 0; i < players.size(); i += 2) {
                if (players[i].second || players[i + 1].second) {
                    // If either player is you, no cheating needed
                    winners.push_back(players[i].second ? players[i] : players[i + 1]);
                } else {
                    // Both players are opponents; you need to cheat
                    cheatCount++;
                    winners.push_back({max(players[i].first, players[i + 1].first), false});
                }
            }
            
            players = winners;
        }
        
        return cheatCount;
    }
};

int main() {
    CheatMinimizer solver;
    
    // Example 1
    vector<int> ratings1 = {1,2,3,4,5,6,7,8};
    int yourRating1 = 5;
    int result1 = solver.minimize(ratings1, yourRating1);
    cout << "Example 1: " << result1 << endl;  // Output: 1
    
    // Example 2
    vector<int> ratings2 = {100, 200, 300};
    int yourRating2 = 301;
    int result2 = solver.minimize(ratings2, yourRating2);
    cout << "Example 2: " << result2 << endl;  // Output: 0
    
    // Example 3
    vector<int> ratings3 = {100, 200, 300};
    int yourRating3 = 50;
    int result3 = solver.minimize(ratings3, yourRating3);
    cout << "Example 3: " << result3 << endl;  // Output: 2
    
    // Example 4
    vector<int> ratings4 = {100, 1, 99, 2, 98, 4, 3, 97, 96, 95, 6, 7, 93};
    int yourRating4 = 50;
    int result4 = solver.minimize(ratings4, yourRating4);
    cout << "Example 4: " << result4 << endl;  // Output: 4
    
    return 0;
}

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
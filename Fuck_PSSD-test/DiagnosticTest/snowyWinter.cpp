#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class SnowyWinter {
 public:
  int snowy_highway_length(vector<int> startPoints, vector<int> endPoints) {
    int mymin = *min_element(startPoints.begin(), startPoints.end());

    int mymax = *max_element(endPoints.begin(), endPoints.end());

    vector<int> road(mymax - mymin, 0);

    for (int i = 0; i < startPoints.size(); ++i) {
      for (int j = startPoints[i]; j < endPoints[i]; ++j) road[j - mymin] = 1;
    }

    int ans = 0;

    for (int i = 0; i < road.size(); ++i) ans += road[i];

    return ans;
  }
};
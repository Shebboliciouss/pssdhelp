#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef istringstream iss;
typedef ostringstream oss;
#define pq priority_queue
#define let(a, b) typeof(b) a(b)
#define all(a) a.begin(), a.end()
#define forall(a, b) for (let(a, b.begin()); a != b.end(); a++)
#define forrall(a, b) for (let(a, b.rbegin()); a != b.rend(); a++)
#define contain(a, b) (find(all(a), b) != a.end())

class Flags {
 public:
  long long numStripes(string numFlags, vector<string> forbidden) {
    long long ans;
    ll numf = atoll(numFlags.c_str());
    int data[20][20], n = forbidden.size();
    //memset(data, 0, sizeof(data));
    for (int i = 0; i < forbidden.size(); i++) {
      iss sin(forbidden[i]);
      int t;
      while (sin >> t) data[i][t] = data[t][i] = 1;
    }
    ll save[2010][20], total[2010];
    total[1] = 0;
    for (int i = 0; i < n; i++) {
      save[1][i] = 1;
      total[1] += save[1][i];
    }
    numf -= total[1];
    if (numf <= 0) return 1;
    for (int i = 2; i <= 2000; i++) {
      total[i] = 0;
      for (int j = 0; j < n; j++) {
        save[i][j] = 0;
        for (int k = 0; k < n; k++)
          if (!data[k][j]) save[i][j] += save[i - 1][k];
        total[i] += save[i][j];
      }
      numf -= total[i];
      if (numf <= 0) return i;
    }
    return 2000 + (numf + total[2000] - 1) / total[2000];
  }
};
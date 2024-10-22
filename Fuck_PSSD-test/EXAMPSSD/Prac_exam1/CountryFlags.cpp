// // #include <vector>
// // #include <string>
// // #include <sstream>
// // #include <iostream>
// // #include <climits>
// // #include <stdlib.h>
// // #include<algorithm>

// // using namespace std;

// // class CountryFlags {
// // public:
// //     long minStripes(string numFlags, vector<string> forbidden) {
// //         long numFlagsLong = stol(numFlags);
// //         int numColors = forbidden.size();

// //         // Parse forbidden relationships
// //         vector<vector<int>> forbiddenColors(numColors, vector<int>());
// //         for (int i = 0; i < numColors; i++) {
// //             istringstream iss(forbidden[i]);
// //             int color;
// //             while (iss >> color) {
// //                 forbiddenColors[i].push_back(color);
// //             }
// //         }

// //         // Initialize dp array with a large value
// //         vector<vector<long>> dp(numFlagsLong + 1, vector<long>(numFlagsLong * 3 + 1, numFlagsLong + 1));
// //         dp[0][0] = 0;

// //         // Fill dp array using dynamic programming
// //         for (long i = 1; i <= numFlagsLong; i++) {
// //             for (long j = 1; j <= i * 3; j++) {
// //                 // Try adding one-striped flag
// //                 if (j >= 1) {
// //                     dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
// //                 }
// //                 // Try adding two-striped flag
// //                 if (j >= 2) {
// //                     dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + 2);
// //                 }
// //                 // Try adding three-striped flag
// //                 if (j >= 3) {
// //                     dp[i][j] = min(dp[i][j], dp[i - 1][j - 3] + 3);
// //                 }

// //                 // Check forbidden relationships
// //                 for (int k = 0; k < numColors; k++) {
// //                     if (i >= 2 && (find(forbiddenColors[k].begin(), forbiddenColors[k].end(), k) != forbiddenColors[k].end() ||
// //                         find(forbiddenColors[k].begin(), forbiddenColors[k].end(), (k + 1) % numColors) != forbiddenColors[k].end())) {
// //                         dp[i][j] = numFlagsLong + 1;
// //                     }
// //                 }
// //             }
// //         }

// //         // Find the minimum number of stripes needed
// //         long minStripes = numFlagsLong + 1;
// //         for (long j = 0; j <= numFlagsLong * 3; j++) {
// //             minStripes = min(minStripes, dp[numFlagsLong][j]);
// //         }

// //         return minStripes;
// //     }
// // };

// // int main() {
// //     CountryFlags flags;
// //     cout << flags.minStripes("10", {"0", "12", "12"}) << endl;  // Output: 3
// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstring>
// #include <climits> // Include this header for LLONG_MAX
// using namespace std;

// class CountryFlags {
// public:
//     long minStripes(string numFlags, vector<string> forbidden) {
//         int n = numFlags.size(); // Number of flags to design
//         int colors = forbidden.size(); // Number of available colors
        
//         // Create a bitmask to represent which colors are forbidden to be neighbors of each other
//         int forbiddenColors[colors];
//         memset(forbiddenColors, 0, sizeof(forbiddenColors));
//         for (int i = 0; i < colors; ++i) {
//             for (char c : forbidden[i]) {
//                 if (c != ' ') {
//                     forbiddenColors[i] |= (1 << (c - '0'));
//                 }
//             }
//         }
        
//         // Dynamic programming to calculate the minimum number of stripes needed
//         vector<long long> dp(1 << colors, LLONG_MAX);
//         dp[0] = 0; // Initially, no stripes are used
        
//         for (int mask = 0; mask < (1 << colors); ++mask) {
//             for (int i = 0; i < colors; ++i) {
//                 if ((mask & (1 << i)) == 0) { // If color i is not yet used
//                     long long cost = 0;
//                     for (int j = 0; j < colors; ++j) {
//                         if (i != j && (mask & (1 << j)) != 0) { // If color j is already used and not forbidden
//                             cost += dp[mask ^ (1 << j)]; // Calculate the cost without color j
//                         }
//                     }
//                     dp[mask | (1 << i)] = min(dp[mask | (1 << i)], cost + 1); // Update the minimum cost
//                 }
//             }
//         }
        
//         // Find the minimum number of stripes for the given number of flags
//         long long ans = LLONG_MAX;
//         for (int mask = 0; mask < (1 << colors); ++mask) {
//             if (dp[mask] * colors >= n) {
//                 ans = min(ans, dp[mask]);
//             }
//         }
        
//         return ans;
//     }
// };

// // int main() {
// //     CountryFlags cf;
// //     vector<string> forbidden0 = {"0","12","12"};
// //     cout << "Example 0: " << cf.minStripes("10", forbidden0) << endl; // Should print 3

// //     vector<string> forbidden1 = {"0","1","2"};
// //     cout << "Example 1: " << cf.minStripes("100", forbidden1) << endl; // Should print 6

// //     vector<string> forbidden2 = {"0","1"};
// //     cout << "Example 2: " << cf.minStripes("10000000000000000", forbidden2) << endl; // Should print 50000000000000000

// //     vector<string> forbidden3 = {"01", "01", "234", "234", "234"};
// //     cout << "Example 3: " << cf.minStripes("10000000000000000", forbidden3) << endl; // Should print 40

// //     vector<string> forbidden4 = {"0123456789", "013456789", "0 23456789", "0123456789", "0123456789", "0123456789", "0123456789", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 4 5 6 7 8 9", "0 1 2 3 456789"};
// //     cout << "Example 4: " << cf.minStripes("10000000000000000", forbidden4) << endl; // Should print 4999999999999996

// //     vector<string> forbidden5 = {"0","1","2","3","4","5"};
// //     cout << "Example 5: " << cf.minStripes("5", forbidden5) << endl; // Should print 1

// //     return 0;
// // }

// int main() {
//   CountryFlags flags;
//   cout << flags.minStripes("10", {"0", "12", "12"}) << endl;  // Output: 3
//   cout << flags.minStripes("100", {"0", "1", "2"}) << endl;   // Output: 6
//   cout << flags.minStripes("100000000000000000", {"0", "1"})
//        << endl;  // Output: 	50000000000000000
//   cout << flags.minStripes("10000000000000000",
//                            {"0 1", "0 1", "2 3 4", "2 3 4", "2 3 4"})
//        << endl;  // Output: 40
//   cout << flags.minStripes("5", {"0", "1", "2", "3", "4", "5"})
//        << endl;  // Output : 1
//   return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int countStripes(long int numFlags, vector<string> forbidden) {
    vector<vector<long int>> dp(numFlags + 1, vector<long int>(3, 0));

    for (int i = 1; i <= numFlags; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = numFlags;

            for (int k = 0; k < 3; k++) {
                if (j == k || forbidden[j].find(k + '0') != string::npos) {
                    continue;
                }

                dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
            }
        }
    }

    return min(dp[numFlags][0], min(dp[numFlags][1], dp[numFlags][2]));
}

int main() {
    cout << countStripes(10, {"012", "012", "012"}) << endl; // Output: 3
    cout << countStripes(100, {"012", "012", "012"}) << endl; // Output: 6
    cout << countStripes(100000000000000000, {"01"}) << endl; // Output: 50000000000000000
    cout << countStripes(10000000000000000, {"234", "234", "234", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789"}) << endl; // Output: 4999999999999996
    cout << countStripes(5, {"012345"}) << endl; // Output: 1

    return 0;
}


#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi; typedef vector<vi> vvi;
typedef vector<string> vs; typedef vector<vs> vvs;
typedef istringstream iss; typedef ostringstream oss;
#define pq priority_queue
#define let(a,b) typeof(b) a(b)
#define all(a) a.begin(),a.end()
#define forall(a,b) for (let(a,b.begin());a!=b.end();a++)
#define forrall(a,b) for (let(a,b.rbegin());a!=b.rend();a++)
#define contain(a,b) (find(all(a),b)!=a.end())

class Flags{
public:
long long numStripes(string numFlags, vector <string> forbidden)
{
long long ans;
ll numf=atoll(numFlags.c_str());
int data[20][20],n=forbidden.size();
memset(data,0,sizeof(data));
for (int i=0;i<forbidden.size();i++)
{
    iss sin(forbidden[i]);
    int t;
    while (sin>>t)
        data[i][t]=data[t][i]=1;
}
ll save[2010][20],total[2010];
total[1]=0;
for (int i=0;i<n;i++)
{
    save[1][i]=1;
    total[1]+=save[1][i];
}
numf-=total[1];
if (numf<=0) return 1;
for (int i=2;i<=2000;i++)
{
    total[i]=0;
    for (int j=0;j<n;j++)
    {
        save[i][j]=0;
        for (int k=0;k<n;k++)
            if (!data[k][j]) save[i][j]+=save[i-1][k];
        total[i]+=save[i][j];
    }
    numf-=total[i];
    if (numf<=0) return i;
}
return 2000+(numf+total[2000]-1)/total[2000];
}
};
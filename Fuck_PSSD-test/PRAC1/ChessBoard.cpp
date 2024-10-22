// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// class ChessBoard {
//  public:
//   int howMany(vector<string> floor) {
//     int n = floor.size();

//     int changes = 0;

//     // Iterate through the grid

//     for (int i = 0; i < n; ++i) {
//       for (int j = 0; j < n; ++j) {
//         // Calculate the expected color based on row and column indices

//         char expectedColor = ((i + j) % 2 == 0) ? 'a' : 'b';

//         // If the tile's color does not match the expected color, increment
//         // changes

//         if (floor[i][j] != expectedColor) {
//           ++changes;
//         }
//       }
//     }

//     return changes;
//   }
// };

// int main() {
//   ChessBoard C;
//   std::cout << C.howMany({"aba", "bbb", "aba"}) << std::endl;  // return 1;
//   std::cout << C.howMany({"wbwbwbwb", "bwbwbwbw", "wbwbwbwb",
//   "bwbwbwbw","wbwbwbwb", "bwbwbwbw", "wbwbwbwb", "bwbwbwbw"})<< std::endl; //
//   return 0; std::cout << C.howMany({"zz", "zz"}) << std::endl;  // return 2;
//   std::cout << C.howMany({"helloand", "welcomet", "osingler",
//   "oundmatc","hsixhund", "redandsi", "xtythree", "goodluck"}) << std::endl;
//   // return 56;

//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define repi(i, p, q) for (long i = p; i < q; i++)
#define repd(i, p, q) for (long i = p; i >= q; i--)
#define sz(x) x.size()
#define INF 2000000000
#define MOD 1000000007

typedef map<int, int> MI;
typedef pair<int, int> PI;
typedef long long int LLI;
typedef long int LI;
typedef int I;

class ChessFloor {
 public:
  int minimumChanges(vector<string> a) {
    int answer = 1000000;
    int index1 = 0;
    int index2 = 0;
    char first[a.size() + 2][a[0].length() + 2];
    char second[a.size() + 2][a[0].length() + 2];
    repi(k, 0, 28) {
      repi(l, 0, 28) {
        if (k == l) continue;
        int flag = 1;
        int count1 = 0, count2 = 0;
        index1 = k;
        index2 = l;
        repi(i, 0, a.size()) {
          flag = 1;
          repi(j, 0, a[0].length()) {
            if (i % 2 == 0) {
              if (flag == 1) {
                first[i][j] = (char)('a' + index1);
                second[i][j] = (char)('a' + index2);
              } else {
                first[i][j] = (char)('a' + index2);
                second[i][j] = (char)('a' + index1);
              }
              flag = -1 * flag;
            } else {
              if (flag == 1) {
                first[i][j] = (char)('a' + index2);
                second[i][j] = (char)('a' + index1);
              } else {
                first[i][j] = (char)('a' + index1);
                second[i][j] = (char)('a' + index2);
              }
              flag = -1 * flag;
            }
            if (a[i][j] != first[i][j]) {
              count1++;
            }
            if (a[i][j] != second[i][j]) {
              count2++;
            }
          }
        }
        answer = min(answer, min(count1, count2));
      }
    }
    return answer;
  }
};

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
using namespace std;

class ChessFloor {
 public:
  int minimumChanges(vector<string> floor) {
    int ans = 999999999;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j) continue;
        int ans1 = 0;
        for (int ii = 0; ii < floor.size(); ii++) {
          for (int jj = 0; jj < floor.size(); jj++) {
            if ((ii + jj) % 2 == 0) {
              if (floor[ii][jj] != char(i + 'a')) ans1++;
            } else {
              if (floor[ii][jj] != char(j + 'a')) ans1++;
            }
          }
        }
        ans = min(ans, ans1);
      }
    }
    return ans;
  }
};
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
©著作权归作者所有：来自51CTO博客作者迷迷糊糊爱睡觉的原创作品，请联系作者获取转载授权，否则将追究法律责任
                                                       TC SRM 663 div2 A
                                                           ChessFloor 暴力 https
    :  // blog.51cto.com/u_15303184/3110732

#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
       using namespace std;

class ChessFloor {
 public:
  int minimumChanges(vector<string> floor) {
    int ans = 999999999;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j) continue;
        int ans1 = 0;
        for (int ii = 0; ii < floor.size(); ii++) {
          for (int jj = 0; jj < floor.size(); jj++) {
            if ((ii + jj) % 2 == 0) {
              if (floor[ii][jj] != char(i + 'a')) ans1++;
            } else {
              if (floor[ii][jj] != char(j + 'a')) ans1++;
            }
          }
        }
        ans = min(ans, ans1);
      }
    }
    return ans;
  }
};
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
©著作权归作者所有：来自51CTO博客作者迷迷糊糊爱睡觉的原创作品，请联系作者获取转载授权，否则将追究法律责任
                                                       TC SRM 663 div2 A
                                                           ChessFloor 暴力 https
    :  // blog.51cto.com/u_15303184/3110732

// Import header files
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
       using namespace std;

// Define the ChessBoard class
class ChessBoard {
 public:
  // Define the countDiff function
  int countDiff(const vector<string>& floor, char f, char s) {
    // Declare and initialize the variables
    int changes = 0;
    int N = floor.size();

    // Iterate the loop N times
    for (int i = 0; i < N; ++i) {
      // Iterate the nested loop N times
      for (int j = 0; j < N; ++j) {
        // Check whether sum of i and j is divisible by 2
        if ((i + j) % 2 == 0) {
          // Check whether the floor value is not equal to f
          if (floor[i][j] != f) {
            // Pre-increment the changes by 1
            ++changes;
          }
        } else {
          // Check whether the floor value is not equal to s
          if (floor[i][j] != s) {
            // Pre-increment the changes by 1
            ++changes;
          }
        }
      }
    }

    // Return the changes
    return changes;
  }

  // Define the howMany function
  int howMany(vector<string> floor) {
    // Declare and initialize the variables
    int N = floor.size();
    int res = N * N;

    // Iterate the loop
    for (char i = 'a'; i <= 'z'; ++i) {
      // Iterate the nested loop
      for (char j = 'a'; j <= 'z'; ++j) {
        // Check whether i is not equal to j
        if (i != j) {
          // Invoke the helper function countDiff
          int currDiffs = min(countDiff(floor, i, j), countDiff(floor, j, i));

          // Store the minimum in res
          res = min(res, currDiffs);
        }
      }
    }

    // Return the result
    return res;
  }
};


// class ChessFloor {
//  public:
//   int minimumChanges(vector<string>);
// };

// int ChessFloor::minimumChanges(vector<string> s) {
//   int minV = 100000;
//   int n = s.size();
//   for (char c1 = 'a'; c1 <= 'z'; c1++) {
//     for (char c2 = 'a'; c2 <= 'z'; c2++)
//       if (c1 != c2) {
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//           for (int j = 0; j < n; j++) {
//             if (((i + j) & 1) && c1 != s[i][j])
//               ans++;
//             else if (!((i + j) & 1) && c2 != s[i][j])
//               ans++;
//           }
//         minV = min(minV, ans);
//       }
//   }
//   return minV;
// }

// Define the main function
int main() {
  // Create a class object
  ChessBoard checker;

  // Test all strings given in the question
  vector<string> f1 = {"aba", "bbb", "aba"};
  cout << checker.howMany(f1) << endl;

  vector<string> f2 = {"wbwbwbwb", "bwbwbwbw", "wbwbwbwb", "bwbwbwbw",
                       "wbwbwbwb", "bwbwbwbw", "wbwbwbwb", "bwbwbwbw"};
  cout << checker.howMany(f2) << endl;

  vector<string> f3 = {"zz", "zz"};
  cout << checker.howMany(f3) << endl;

  vector<string> f4 = {"helloand", "welcomet", "osingler", "oundmatc",
                       "hsixhund", "redandsi", "xtythree", "goodluck"};
  cout << checker.howMany(f4) << endl;
  return 0;
}

/*

-Import the required header files.

    -Define the ChessBoard class.

        -Declare the public member,

            -Define the helper function countDiff(floor, f, s),

                -Declare and initialize the variables changes and N.

                -Iterate the loop N times with the loop variable i,

                    -Iterate the nested loop N times with the loop variable j,

                        -Check whether the sum of i and j is divisible by 2,

                            -If so, check whether the floor value is not equal
to f,

                                -If so, pre-increment the changes by 1.

                            -If not, check whether the floor value is not equal
to f,

                                -If so, pre-increment the changes by 1.

                -Finally, return changes.

        -Define the howMany(floor) function.

            -Declare and initialize the variables.

            -Iterate the nested loop with the loop variables i and j,

                -Check whether i is not equal to j,

                    -If so, invoke the helper function countDiff.

            -Return the result.

-Define the main function,

    -Create an object for ChessBoard.

    -Test all test cases given in the question.

*/
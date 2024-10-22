// #include <algorithm>
// #include <iostream>
// using namespace std;

// class GoingUp {
// public:
//     int minRemove(int a, int b, int c) {
//         // Store the candies in an array for easier manipulation
//         int candies[3] = {a, b, c};

//         // Sort the candies in ascending order
//         std::sort(candies, candies + 3);

//         // Check if the sorted candies form a strictly increasing sequence
//         if (candies[0] == candies[1] || candies[1] == candies[2]) {
//             return -1; // It's not possible to form a strictly increasing
//             sequence
//         }

//         // Calculate the number of candies Sergey needs to eat
//         int totalEaten = 0;
//         if (candies[0] == candies[1]) {
//             // If the first two boxes have the same number of candies, we
//             need to make them strictly increasing int diff = candies[2] -
//             candies[1]; totalEaten += diff - 1; // Eat candies to make them
//             strictly increasing candies[2] = candies[1] + 1;
//         }
//         if (candies[1] == candies[2]) {
//             // If the last two boxes have the same number of candies, we need
//             to make them strictly increasing int diff = candies[1] -
//             candies[0]; totalEaten += diff - 1; // Eat candies to make them
//             strictly increasing candies[0] = candies[1] - 1;
//         }

//         // Now, we have three distinct numbers in ascending order
//         // Calculate the number of candies Sergey needs to eat to maintain
//         the strictly increasing sequence totalEaten += std::max(0, candies[1]
//         - candies[0] - 1); totalEaten += std::max(0, candies[2] - candies[1]
//         - 1);

//         return totalEaten;
//     }
// };

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// class GoingUp
// {
// public:
//     int minRemove(vector<int>& candies) {
//     int n = candies.size();
//     vector<int> dp(n, 1);

//     for (int i = 1; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (candies[i] > candies[j] && dp[i] < dp[j] + 1) {
//                 dp[i] = dp[j] + 1;
//             }
//         }
//     }

//     return *max_element(dp.begin(), dp.end());
// }
// };

// int main() {
//     GoingUp G;
//     vector<int> example1 = {15, 40, 22};
//     vector<int> example2 = {5, 6, 6};
//     vector<int> example3 = {6,1,3000};
//     vector<int> example4 = {6,4,2};
//     vector<int> example5 = {4,2,6};
//     vector<int> example6 = {1,1234,3000};
//     vector<int> example7 = {2789,2400,1693};

//     int result1 =  G.minRemove(example1);
//     int result2 =  G.minRemove(example2);
//     int result3 =  G.minRemove(example3);
//     int result4 =  G.minRemove(example4);
//     int result5 =  G.minRemove(example5);
//     int result6 =  G.minRemove(example6);
//     int result7 =  G.minRemove(example7);

//     cout << "Result for example 1: " << result1 << endl;
//     cout << "Result for example 2: " << result2 << endl;
//     cout << "Result for example 3: " << result3 << endl;
//     cout << "Result for example 4: " << result4 << endl;
//     cout << "Result for example 5: " << result5 << endl;
//     cout << "Result for example 6: " << result6 << endl;
//     cout << "Result for example 7: " << result7 << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

int minCandiesToMakeNiceBoxes(int a, int b, int c) {
  if (a >= b && b >= c) {
    // Boxes are already in non-increasing order, cannot make them nice.
    return -1;
  }

  int minCandies = 0;

  if (a >= b) {
    // Move candy from 'a' to 'b' to make 'a < b'.
    int diff =
        a - b + 1;  // Adding 1 to make sure 'a' is strictly less than 'b'.
    minCandies += diff;
    a -= diff;
  }

  if (b >= c) {
    // Move candy from 'b' to 'c' to make 'b < c'.
    int diff =
        b - c + 1;  // Adding 1 to make sure 'b' is strictly less than 'c'.
    minCandies += diff;
    b -= diff;
  }

  if (a >= b) {
    // If 'a' is still greater than 'b', it's not possible to make them nice.
    return -1;
  }

  // Now, the boxes are in strictly increasing order.
  return minCandies;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int result = minCandiesToMakeNiceBoxes(a, b, c);

  cout << result << endl;

  return 0;
}

// int main(){
//    cout <<minCandiesToMakeNiceBoxes(15, 40, 22) << endl;
//     cout << minCandiesToMakeNiceBoxes(5,6,6) << endl;  //2
//     cout <<minCandiesToMakeNiceBoxes(6,1,3000) << endl;  //-1
//    cout <<minCandiesToMakeNiceBoxes(6,4,2) << endl;
//   cout <<minCandiesToMakeNiceBoxes(4,2,6) << endl;
//    cout << minCandiesToMakeNiceBoxes(1,1234,3000) << endl;
//     cout <<minCandiesToMakeNiceBoxes(2789,2400,1693) << endl; //1806
//     return 0;
// }

class ThreeIncreasing {
 public:
  int minEaten(int a, int b, int c) {
    if (c < 3) return -1;
    if (b < 2) return -1;
    return max(0, b - c + 1) + max(0, max(a - c + 2, a - b + 1));
    return 0;
  }
};

class ThreeIncreasing {
    public:
    int minEaten(int a, int b, int c) {
        int ans = 0;
        if (c == 1) return -1;
        if (b >= c) ans += b - c + 1, b = c - 1;
        if (b == 1) return -1;
        if (a >= b) ans += a - b + 1;
        return ans;
    }
};

struct ThreeIncreasing{
int minEaten(int a, int b, int c)
{
    int ret=10000000;
    for(int i = 0; i < a; i++)
    {
    	for(int j = 0; j < b; j++)
    	{
    		for(int k = 0; k < c; k++)
    		{
    			if(a-i < b-j && b-j < c-k)
    			{
    				ret = min(ret, i + j + k);
    			}
    		}
    	}
    }
    if(ret==10000000)ret=-1;
    return ret;
}
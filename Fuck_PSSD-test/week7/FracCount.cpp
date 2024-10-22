#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class FracCount {
 public:
  // int position(int numerator, int denominator) {
  //     std::vector<int> fracCount(1001, 0);
  //     for (int i = 2; i <= denominator; ++i) {
  //         fracCount[i] = fracCount[i - 1] + i;
  //     }
  //     return fracCount[denominator] - (denominator - numerator);
  // }

  // int gcd(int num, int den){
  //     if(den == 0){
  //         return num;
  //     }
  //     return gcd(den, num % den);
  //     // Euclidean algorithm
  //     return den == 0 ? num : gcd(den, num % den);
  // }

  // int position(int numerator, int denominator) {
  //     int count = 0;
  //     for (int d = 2; d <= denominator; ++d) {
  //         for (int n = 1; n < d; ++n) {
  //             if (__gcd(n, d) == 1) {
  //                 ++count;
  //                 if (n == numerator && d == denominator) {
  //                     return count;
  //                 }
  //             }
  //         }
  //     }
  //     return -1; // This line should never be reached
  // }

  // int calculatePosition(int n, int  den, int numerator, int denominator,
  // vector<pair<int, int>, int>& data){
  //     // Base case: When the numerator is 1, return 1

  //     // if (n >= den || den > denominator) {
  //     //     return 1;
  //     // }
  //     if (n >= denominator){
  //         return 0;
  //     }
  //     if (n == numerator && den == denominator) {
  //         return 1;
  //     }

  //     // Check if the result is already computed and stored in the memo map
  //     if (data.find({numerator, denominator}) != data.end()) {
  //         return data[{numerator, denominator}];
  //     }

  //     // Calculate the position recursively by considering fractions with
  //     smaller denominators

  //     // // If the denominator is equal to the current denominator, add the
  //     numerator
  //     // if (__gcd(num, denominator) == 1) {
  //     //     count += num;
  //     // }

  //     // Store the computed result in the memo map
  //     // data[{n, den}] = count;

  //     return count;
  // }

  // int position(int numerator, int denominator) {
  //     static vector<pair<int, int>, int> data;
  //     int count = 0;
  //     pair<int, int> lastPair = data.back().first;
  //     int lastInt = data.back().second;
  //     pair<int, int> lastPair = data[data.size() - 1].first;
  // int lastInt = data[data.size() - 1].second;
  //     for (int d = 2; d <= denominator; d++) {
  //         count += calculatePosition(n+1, d, numerator, denominator, data);
  //         data.push_back(make_pair(n,d), count);
  //     }

  //     // a loop that iterate through over the possible denominators from 2
  //     till the given denominators return calculatePosition(1,2, numerator,
  //     denominator, data);
  // }


  int position(int numerator, int denominator) {
    static map<pair<int, int>, int> data;
    
    if (data.find({numerator, denominator}) != data.end()) {
      return data[{numerator, denominator}];
    }

    // Initialize variables for the current calculation
    int lastDenom = 2;
    int lastNumer = 1;
    int count = 0;

    // auto rit = data.rbegin();

    // if (rit != data.rend()) {
    //     pair<int, int> lastKey = rit->first;
    //     lastDenom = lastKey.second;
    //     lastNumer = lastKey.first;
    //     count = rit->second;
    // }

    for (int d = lastDenom; d <= denominator; d++) {
      for (int n = lastNumer; n < d; n++) {
        if (__gcd(n, d) == 1) {
          // Check if the result is already computed then return the computed
          // data
          if (data.find({n, d}) != data.end()) {
            count = data[{n, d}];

          } else {
            count++;
            // Store the computed result in the map
            data[{n, d}] = count;
          }

          if (n == numerator && d == denominator) {
            return count;
          }
        }
      }
    }
    return 0;
  }

  // int position(int numerator, int denominator) {
  //     // Create a dynamic programming table to store results
  //     vector<vector<int>> dp(denominator + 1, vector<int>(numerator + 1, 0));

  //     // Initialize count to 0
  //     int count = 0;

  //     // Iterate over possible denominators
  //     for (int d = 2; d <= denominator; ++d) {
  //         // Iterate over possible numerators
  //         for (int n = 1; n < d; ++n) {
  //             // Check if the fraction is irreducible (GCD is 1)
  //             if (__gcd(n, d) == 1) {
  //                 count++;

  //                 // Store the count in the dynamic programming table
  //                 dp[d][n] = count;

  //                 // If the current fraction matches the target, return the
  //                 count if (n == numerator && d == denominator) {
  //                     return count;
  //                 }
  //             }
  //         }
  //     }

  //     // Return the count for the target fraction
  //     return dp[denominator][numerator];
  // }

  int position(int numerator, int denominator) {
      // Create a table to store results for all irreducible fractions
      vector<vector<int>> dp(denominator + 1, vector<int>(denominator + 1,
      0));

      // Initialize a count to keep track of the position
      int count = 0;

      for (int d = 2; d <= denominator; ++d) {
          for (int n = 1; n < d; ++n) {
              if (__gcd(n, d) == 1) {
                  count++;
                  dp[n][d] = count;

                  // Check if this is the target fraction
                  if (n == numerator && d == denominator) {
                      return count;
                  }
              }
          }
      }

      // If the target fraction is not found, return 0
      return 0;
  }
};

int main() {
  FracCount c;
  cout << c.position(1, 2) << endl;       // Return: 1
  cout << c.position(5, 6) << endl;       // Return: 11
  cout << c.position(999, 1000) << endl;  // Return: 304191
  cout << c.position(777, 778) << endl;   // Return: 184139
  cout << c.position(12, 625) << endl;    // Return: 118493
  cout << c.position(1, 111) << endl;     // Return: 3716
  cout << c.position(1, 512) << endl;     // Return: 79596
  cout << c.position(2, 889) << endl;     // Return: 239959
  cout << c.position(2, 3) << endl;       // Return: 3
  cout << c.position(2, 5) << endl;       // Return: 7
  cout << c.position(37, 75) << endl;     // Return: 1715
  cout << c.position(65, 72) << endl;     // Return: 1585
  cout << c.position(13, 15) << endl;     // Return: 70
  cout << c.position(81, 1000) << endl;   // Return: 303824
  return 0;
}
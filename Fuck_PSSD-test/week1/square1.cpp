#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <vector>
#include <string>
using namespace std;

class SquareOfDigits {
public:
    int getMax(vector<string> data) {
        int rows = data.size();
        int cols = data[0].size();
        int maxSize = 1; // Initialize the maximum square size found so far to 1

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Consider (i, j) as the top-left corner of a potential square
                int size = 1; // Current square size

                // Try to expand the square and check if all corners have the same digit
                while (i + size < rows && j + size < cols) {
                    char digit = data[i][j];

                    // Check if all corners have the same digit
                    if (data[i + size][j] == digit && data[i][j + size] == digit && data[i + size][j + size] == digit) {
                        size++; // Increment the square size if all corners have the same digit
                    } else {
                        break; // Stop expanding if any corner has a different digit
                    }
                }

                maxSize = max(maxSize, size); // Update the maximum square size found so far
            }
        }

        return maxSize * maxSize; // Return the total number of cells in the largest square
    }
};

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SquareOfDigits {
public:
    int getMax(vector<string> s) {
        int n = s.size();
        int m = s[0].size();
        int res = 0;

        // Preprocess the grid to store the count of each digit in each cell
        vector<vector<vector<int>>> count(n, vector<vector<int>>(m, vector<int>(10, 0)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count[i][j][s[i][j] - '0'] = 1;
                if (i > 0) {
                    for (int k = 0; k < 10; k++) {
                        count[i][j][k] += count[i - 1][j][k];
                    }
                }
                if (j > 0) {
                    for (int k = 0; k < 10; k++) {
                        count[i][j][k] += count[i][j - 1][k];
                    }
                }
                if (i > 0 && j > 0) {
                    for (int k = 0; k < 10; k++) {
                        count[i][j][k] -= count[i - 1][j - 1][k];
                    }
                }
            }
        }

        // Iterate through each cell as the top-left corner of a potential square
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = min(n - i, m - j); k > 0; k--) {
                    // Check if all four corners of the square have the same digit
                    bool valid = true;
                    for (int digit = 0; digit < 10; digit++) {
                        int cornerSum = count[i + k - 1][j + k - 1][digit];
                        if (i > 0) {
                            cornerSum -= count[i - 1][j + k - 1][digit];
                        }
                        if (j > 0) {
                            cornerSum -= count[i + k - 1][j - 1][digit];
                        }
                        if (i > 0 && j > 0) {
                            cornerSum += count[i - 1][j - 1][digit];
                        }
                        if (cornerSum != k * k) {
                            valid = false;
                            break;
                        }
                    }

                    // If all corners have the same digit, update the result
                    if (valid) {
                        res = max(res, k * k);
                        break;
                    }
                }
            }
        }

        return res;
    }
};


class SquareOfDigits {
 public:
  int getMax(vector<string> s) {
    int i, a, j, res = 0;
    for (i = 0; i < s.size(); i++) {
      for (a = 0; a < s[0].size(); a++) {
        for (j = 0;; j++) {
          if (i + j >= s.size() || a + j >= s[0].size()) {
            break;
          }
          if (s[i][a] == s[i + j][a] && s[i][a] == s[i + j][a + j] && s[i][a] == s[i][a + j]) {
            if ((j + 1) * (j + 1) > res) {
              res = (j + 1) * (j + 1);
            }
          }
        }
      }
    }
    return res;
  }
};

int main() {
  SquareOfDigits squareOfDigits;

  // Test cases
  vector<string> grid1 = {"12", "34"};
  cout << "Test case 1: " << squareOfDigits.getMax(grid1) << endl;  // 1

  vector<string> grid2 = {"1255", "3455"};
  cout << "Test case 2: " << squareOfDigits.getMax(grid2) << endl;  // 4

  vector<string> grid3 = {"42101", "22100", "22101"};
  cout << "Test case 3: " << squareOfDigits.getMax(grid3) << endl;  // 9

  vector<string> grid4 = {"1234567890"};
  cout << "Test case 4: " << squareOfDigits.getMax(grid4) << endl;  // 1

  vector<string> grid5 = {"9785409507", "2055103694", "0861396761",
                          "3073207669", "1233049493", "2300248968",
                          "9769239548", "7984130001", "1670020095",
                          "8894239889", "4053971072"};
  cout << "Test case 5: " << squareOfDigits.getMax(grid5) << endl;  // 49

  return 0;
}
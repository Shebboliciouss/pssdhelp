#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PerfectWord {
 public:
  int longest(string W) {
    string temp_result = "";
    string result = "";
    string final_result = "";

    for (int counter = 0; counter < W.length() - 1; ++counter) {
      if (W[counter] <= W[counter + 1]) {
        temp_result += W[counter];
      } else {
        temp_result += W[counter];
        result = result.length() < temp_result.length() ? temp_result : result;
        temp_result = "";
      }
    }

    temp_result += W[W.length() - 1];
    result = result.length() < temp_result.length() ? temp_result : result;

    if (result.length() > 1) {
      final_result = result;
      for (int counter = 0; counter < result.length() - 1; ++counter) {
        if (result[counter].length() <= result[counter + 1].length()) {
          if (final_result.length() < result[counter + 1].length()) {
            final_result = result[counter + 1];
          }
        }
      }
      cout << "Longest substring in alphabetical order is: " << final_result
           << endl;
    } else {
      cout << "Longest substring in alphabetical order is: " << result << endl;
    }

    return 0;
  }
};

int main() {
  PerfectWord p;

  std::cout << p.longest("ABCDEFG") << std::endl;  // Output: 7

  std::cout << p.longest("GFEDCBA") << std::endl;  // Output: 1

  std::cout << p.longest("ACBB") << std::endl;  // Output: 3

  std::cout << p.longest("ACCCCBB") << std::endl;  // Output: 5

  return 0;
}

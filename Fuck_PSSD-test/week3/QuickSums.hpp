#include <algorithm>
#include <iostream>
#include <limits.h>
#include <string>

class QuickSums {
  int getSums(std::string numbers, int sum, int index, int sumSoFar) {
    if (index == numbers.size()) {
      if (sumSoFar == sum) {
        return 0;
      }
      return INT_MAX;
    }

    int minAdditions = INT_MAX;

    int currentNumber = 0;
    for (int i = index; i < numbers.size(); i++) {
      currentNumber = currentNumber * 10 + (numbers[i] - '0');

      if (sumSoFar + currentNumber <= sum) {
        int additions = getSums(numbers, sum, i + 1, sumSoFar + currentNumber);
        if (additions != INT_MAX) {
          minAdditions = std::min(minAdditions, additions + 1);
        }
      }
    }

    return minAdditions;
  }

public:
  QuickSums(){};
  int minSums(std::string numbers, int sum) {
    int additions = getSums(numbers, sum, 0, 0);
    return (additions == INT_MAX) ? -1 : additions - 1;
  }
};
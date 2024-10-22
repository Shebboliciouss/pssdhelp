#include "Finder.h"
#include <iostream>
#include <chrono>

// After function call
auto stop = std::chrono::high_resolution_clock::now();

int main() {
  Finder a;
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<int> ind = a.findSubstrings("7562976595726958629", "9588");
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << duration.count() << std::endl;

  return 0;
}


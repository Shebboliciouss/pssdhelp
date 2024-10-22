#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

// example: area = 16, --> 1*16, --(2*8)-- , 4*4,
//                 30, --> 1*30, 2*15, 3*10, 5*6, 
class RugSizes {
 public:
  int rugCount(int area) {
    int result = 0;
    // Calculate the square root of the area
    int n = round(sqrt(area));
    // Loop through factors of the area
    for (int i = 1; i <= n; i++) {
      // Check if i is a factor of the area
      if (area % i == 0){
        int w = i;            // width is 'i'
        int l = area/i;      // length is 'area / i'

        // Check if both width and length are even numbers, and the size is not a square
        if(w % 2 == 0 && l % 2 == 0 && w*w != area){
            continue;
        } else{
            result++;
        }
        
      }
    }
    return result;
  }
};

int main() {
    RugSizes rugSizes;
    
    // Test cases
    std::cout << rugSizes.rugCount(4) << std::endl; // Expected output: 2
    std::cout << rugSizes.rugCount(8) << std::endl; // Expected output: 1
    std::cout << rugSizes.rugCount(30) << std::endl;
    std::cout << rugSizes.rugCount(100000) << std::endl;
    std::cout << rugSizes.rugCount(98415) << std::endl;
    std::cout << rugSizes.rugCount(6241) << std::endl;
    std::cout << rugSizes.rugCount(99997) << std::endl;
    std::cout << rugSizes.rugCount(99991) << std::endl;
    std::cout << rugSizes.rugCount(64) << std::endl;
    std::cout << rugSizes.rugCount(4096) << std::endl;
    std::cout << rugSizes.rugCount(8192) << std::endl;
    std::cout << rugSizes.rugCount(8193) << std::endl;
    
    return 0;
}

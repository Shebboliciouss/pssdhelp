#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EggCartons {
 public:
  int minCartons(int n) {
    if (n < 6 || n % 2 != 0){
        return -1;
    } else if (n == 6 || n == 8){
        return 1;
    } else {
        int eight = n/8;
        for (int i = eight; i >= 0; i--){
            int remainingEggs = n-(i*8);
            if(remainingEggs % 6 == 0){
                return (i + (remainingEggs/6));
            }
        }
        return -1;
    }
  }
};


    //   int numEight = n / 8;
    //   for (int i = numEight; i >= 0; i--) {
    //     if ((n - i * 8) % 6 == 0)
    //         return i + (n - i * 8) / 6;
    //   }
    //   return -1;

// class EggCartons {
//  public:
//     int minCartons(int n) {

//     cout << "n = " << n << endl;
//     // Base cases - Less than 6 or odd.
//     if ((n < 6) || (n % 2 != 0)) {
//         cout << "n1 = " << n << endl;
//         cout << "Return n1 = -1" << endl;
//       return -1;
//       // End cases - Add to the count for 6 or 8.
//     } else if ((n == 6) || (n == 8)) {
//       cout << "n2 = " << n << endl;
//       cout << "Return n2 = 1" << endl;
//       return 1;
//       // Counters - Recur minusing by 6 and by 8 essentially finding the
//       // combinations of where they are divisible.
//     } else {
//         cout << "n3 = " << n << endl;
//       int six = minCartons(n - 6);
//       cout << "n3.3 = " << n << endl;
//       int eight = minCartons(n - 8);
//       // All possible cases.
//       if ((six == -1) && (eight == -1)) {
//         cout << "n4 = " << six << "," << eight << endl;
//         cout << "Return(-1): -1"  << endl;
//         return -1;

//       } else if ((six != -1) && (eight == -1)) {
//         cout << "n5 = " << six << "," << eight << endl;
//         cout << "Return(six+1): " << (six + 1) << endl;
//         return (six + 1);
//       } else if ((six == -1) && (eight != -1)) {
//         cout << "n6 = " << six << "," << eight<< endl;
//         cout << "Return(eight+1): " << (eight + 1) << endl;
//         return (eight + 1);
//       } else {
//         if (six < eight) {
//             cout << "n7 = "<< six << "," << eight << endl;
//           cout << "Return6: " << (six + 1) << endl;
//           return (six + 1);
//         } else {
//             cout << "n8 = " << six << "," << eight << endl;
//           cout << "Return(eight+1+1): " << (eight + 1) << endl;
//           return (eight + 1);
//         }
//       }
//     }
//     return 0;
//   }
// };

int main() {
    EggCartons eggCartons;
    
    cout << eggCartons.minCartons(20) << endl; // Output: 3
    cout << eggCartons.minCartons(24) << endl; // Output: 3
    cout << eggCartons.minCartons(15) << endl; // Output: -1
    cout << eggCartons.minCartons(4) << endl; // Output: -1
    cout << eggCartons.minCartons(6) << endl; // Output: 1
    
    return 0;
}

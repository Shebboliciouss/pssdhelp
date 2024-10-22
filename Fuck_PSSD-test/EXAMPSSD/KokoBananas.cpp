// #include <iostream>
// #include <vector>
// #include <algorithm>

// class KokoBananas {
// public:
//     // Function to find the last hand from which Koko will eat her last
//     banana int lastHand(std::vector<int> hands, int K) {
//         // Initialize the left and right bounds for binary search
//         int left = 1;
//         int right = *std::max_element(hands.begin(), hands.end());

//         // Perform binary search to find the minimum rate at which Koko can
//         eat bananas while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (canEatAll(hands, K, mid)) {
//                 right = mid;
//             } else {
//                 left = mid + 1;
//             }
//         }

//         // The left bound will contain the last hand from which Koko will eat
//         her last banana return left;
//     }

// private:
//     // Function to check if Koko can eat all bananas at a given rate
//     bool canEatAll(const std::vector<int>& hands, int K, int rate) {
//         int eaten = 0;
//         for (int i = 0; i < hands.size(); ++i) {
//             // Calculate how many bananas can be eaten from the current hand
//             at the given rate eaten += (hands[i] + rate - 1) / rate;
//         }
//         // Check if the total number of eaten bananas is less than or equal
//         to K return eaten <= K;
//     }
// };

// #include <iostream>
// #include <vector>
// // Class declaration
// class KokoBananas {
//   // access specifier
//  public:
//   int lastHand(std::vector<int> hands, int k) {
//     int lastHandIndex = 0;
//     for (int a = 0; a < k; a++) {
//       int maxBananas = hands[0];
//       int maxIndex = 0;
//       for (int j = 1; a < hands.size(); j++) {
//         if (hands[j] > maxBananas) {
//           maxBananas = hands[j];
//           maxIndex = j;
//         }
//       }
//       hands[maxIndex]--;
//       if (hands[lastHandIndex] == 0) {
//         lastHandIndex = maxIndex;
//       }
//     }
//     return lastHandIndex;
//   }
// };

// #include <iostream>
// #include <vector>

// class KokoBananas {
// public:
//     int lastHand(std::vector<int> hands, int k) {
//         int lastHandIndex = 0;
//         for (int a = 0; a < k; a++) {
//             int maxBananas = hands[0];
//             int maxIndex = 0;
//             for (int j = 1; j < hands.size(); j++) {  // Fixed the loop variable 'j'
//                 if (hands[j] > maxBananas) {
//                     maxBananas = hands[j];
//                     maxIndex = j;
//                 }
//             }
//             hands[maxIndex]--;
//             if (hands[lastHandIndex] == 0) {
//                 lastHandIndex = maxIndex;
//             }
//         }
//         return lastHandIndex;
//     }
// };

// #include <iostream>
// #include <vector>

// class KokoBananas {
// public:
//     int lastHand(std::vector<int> hands, int k) {
//         int left = 1;
//         int right = 1000000000;  // Set a high upper bound for binary search
        
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             int bananasEaten = 0;
            
//             for (int i = 0; i < hands.size(); i++) {
//                 bananasEaten += (hands[i] + mid - 1) / mid;
//             }
            
//             if (bananasEaten <= k) {
//                 right = mid;
//             } else {
//                 left = mid + 1;
//             }
//         }
        
//         return left;  // Return the correct hand index
//     }
// };



// int main() {
//     KokoBananas kb;
//     std::vector<int> hands = {5,8};
//     int k = 4;
//     int res = kb.lastHand(hands, k);
//     std::cout << "Result: " << res << std::endl;
//     return 0;
// }

// #include <vector>
// using namespace std;
// class CarrotBoxesEasy {
// public:
//   int theIndex(vector<int> carrots, int k) {
//     int highestIndex = -1;
//     int highestCarrots = 0;
//     for (int l = 0; l < k; l++) {
//       highestCarrots = 0;
//       highestIndex = -1;
//       for (int i = 0; i < carrots.size(); i++) {
//         if (carrots[i] > highestCarrots) {
//           highestCarrots = carrots[i];
//           highestIndex = i;
//         }
//       }
//       carrots[highestIndex]--;
//     }
//     return highestIndex;
//   }
// };

#include <vector>
#include <iostream>
using namespace std;
class KokoBananas{
public:
  int lastHand(vector<int> carrots, int k) {
    int highestIndex = -1;
    int highestCarrots = 0;
    for (int l = 0; l < k; l++) {
      highestCarrots = 0;
      highestIndex = -1;
      for (int i = 0; i < carrots.size(); i++) {
        if (carrots[i] > highestCarrots) {
          highestCarrots = carrots[i];
          highestIndex = i;
        }
      }
      carrots[highestIndex]--;
    }
    return highestIndex;
  }
};

class CarrotBoxesEasy {
public:
  int theIndex(vector <int> carrots, int K) {

	  int tmp=0;
	  for(int i=0 ; i<K ; i++){
		  int tmpmax=0; 
		  for(int j=0 ; j<carrots.size() ; j++){
			  if(carrots[j] > tmpmax){
				  tmpmax = carrots[j];
				  tmp = j;
			  }
		  }
		  carrots[tmp]--;
	  }

	  return tmp;
  }
};

public class CarrotBoxesEasy
{
    public int theIndex(int[] carrots, int K)
    {
        int index = 0;
        for (int k = 0; k < K; k++)
        {
            index = 0; //これを忘れた
            for (int i = 1; i < carrots.Length; i++)
                if (carrots[index] < carrots[i])
                    index = i;
            carrots[index]--;
        }
        return index;
    }
}

int main() {
  // Create an instance of the KokoBananas class
  KokoBananas solution;

  // Test cases
  std::vector<int> hands1 = {5, 8};
  int K1 = 3;
  std::cout << "Test 1: " << solution.lastHand(hands1, K1) << std::endl;

  std::vector<int> hands2 = {5, 8};
  int K2 = 4;
  std::cout << "Test 2: " << solution.lastHand(hands2, K2) << std::endl;

  std::vector<int> hands3 = {4, 9, 5};
  int K3 = 18;
  std::cout << "Test 3: " << solution.lastHand(hands3, K3) << std::endl;

  std::vector<int> hands4 = {13, 75, 24, 55};
  int K4 = 140;
  std::cout << "Test 4: " << solution.lastHand(hands4, K4) << std::endl;

  std::vector<int> hands5 = {14, 36, 52, 86, 27, 97, 3, 67};
  int K5 = 300;
  std::cout << "Test 5: " << solution.lastHand(hands5, K5) << std::endl;

  return 0;
}
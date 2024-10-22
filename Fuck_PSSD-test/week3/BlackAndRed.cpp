#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BlackAndRed{
    public: 
    int cut(std::string deck) {
        int n = deck.size();
        // int res = 0, midpoint = 0, point = 0;
        // for (int i = 0; i < n; i++){
        //     if (deck[i] == 'R'){
        //         point--;
        //     }else{
        //         point++;
        //     }
        //     if (point < midpoint){
        //         midpoint = point;
        //         res = i+1;
        //     }
        // }
        // cout << point << endl;
        // return res;
        
        int redCount = 0;
        int blackCount = 0;
        int minCut = n+1;  // Initialize with the maximum possible value

        // Iterate through the deck and simulate turning over the cards
        for (int i = 0; i < n; i++) {
            if (deck[i] == 'R') {
                redCount++;
            } else {
                blackCount++;
            }

            if (redCount > blackCount){
                    redCount = 0;
                    blackCount = 0;
                    int res = i+1;
                    minCut = res;
            }

            // //Calculate the difference between red and black cards seen so far
            // int diff = redCount - blackCount;
            
            // //Update the minimum cut position
            // minCut = std::min(minCut, std::max(diff, 0));
        }
        if (minCut == n+1){
            minCut = 0;
        }

        return minCut;
        //return index;
// private:
//     bool winner(string deck){
//         int length = deck.length();
// 		int value = 0;
// 		for(int i = 0; i<length; ++i){
// 			if(value<0){
// 				return false;
// 			} else {
// 				if(deck[i] == 'B'){
// 					value++;
// 				} else {
// 					value--;
// 				}
// 			}
// 		}
// 		return true;
// 	}
// public:
// 	int cut(string deck){
// 		int length = deck.length();
// 		for(int i = 0; i<length; i++){
// 			string topCut = deck.substr(0, i);
// 			string bottomCut = deck.substr(i, length-i);
// 			string newDeck = bottomCut + topCut;
// 			if(winner(newDeck)){
// 				return i;
// 			}
// 		}
// 	}
    }
};

int main() {
    BlackAndRed solver;

    // Test cases
    std::cout << "Test Case 1: " << solver.cut("BRBRBR") << " (Expected: 0)" << std::endl;
    std::cout << "Test Case 2: " << solver.cut("RBRBRB") << " (Expected: 1)" << std::endl;
    std::cout << "Test Case 3: " << solver.cut("BBBRRRRB") << " (Expected: 7)" << std::endl;
    std::cout << "Test Case 4: " << solver.cut("BR") << " (Expected: 0)" << std::endl;
    std::cout << "Test Case 5: " << solver.cut("RBRBBRRRRBBBRBBRRBRBBRRRBRBBBRBRBRBRRB") << " (Expected: 9)" << std::endl;

    return 0;
}
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        // Initialize the counters for each color combination--> 1 starts with white and 2 starts with black
        int counter1 = 0;
        int counter2 = 0;
        int n = cardFront.size();
        for(int i = 0; i < n; i++){
            if (i % 2 == 0 && cardFront[i] == 'W'){
                counter1++;
            } else if (i % 2 == 0 && cardFront[i] == 'B'){
                counter2++;
            } else if (i % 2 == 1 && cardFront[i] == 'B'){
                counter1++;
            } else if (i % 2 == 1 && cardFront[i] == 'W'){
                counter2++;
            }
        }
        
        return std::min(counter1, counter2);
    }
};

int main() {
    BlackAndWhiteSolitaire bws;
    
    // Test case 0
    cout << bws.minimumTurns("BBBW") << endl; //== 1);  
    
    // Test case 1
    cout << bws.minimumTurns("WBWBW") << endl; //== 0);
    
    // Test case 2
    cout << bws.minimumTurns("WWWWWWWWW") << endl; //== 4);
    
    // Test case 3
    cout << bws.minimumTurns("BBWBWWBWBWWBBBWBWBWBBWBBW") << endl; //== 10);

    // Additional test cases
    // Test case 4: Testing with all black cards
    cout << bws.minimumTurns("BBBBB") << endl; //== 2);

    // Test case 5: Testing with alternating colors starting with white
    cout << bws.minimumTurns("WBWBW") << endl; //== 0);

    // Test case 6: Testing with alternating colors starting with black
    cout << bws.minimumTurns("BWBWB") << endl; //== 0);

    // Test case 7: Testing with a sequence of the same color followed by a sequence of the other color
    cout << bws.minimumTurns("BBBWWW") << endl; //== 2);

    return 0;
}

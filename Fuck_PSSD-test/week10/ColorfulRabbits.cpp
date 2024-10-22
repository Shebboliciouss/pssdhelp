#include <map>
#include <vector>
#include <iostream>
using namespace std;

class ColorfulRabbits {
public:
    int getMinimum(vector<int> replies) {
        // Store the counts of each unique reply
        map<int, int> unique_replies;

        // Count the number of rabbits that gave the same/unique replies
        for (auto reply : replies) {
            unique_replies[reply]++;
        }

        int complete_group;
        int total = 0;
        
        // Iterate through the unique replies
        for (auto i = unique_replies.begin(); i != unique_replies.end(); i++) {

            // there are (unique reply value + 1) with that colour --> +1 for itself
            int num_of_same_colour_rabbits = i->first + 1;

            // Count of rabbits with the same reply
            int num_of_responses = i->second;
            
            // Calculate how many complete groups can be formed
            if(num_of_responses % num_of_same_colour_rabbits == 0){
                complete_group = num_of_responses / num_of_same_colour_rabbits;
            } else{
                // can form another group with the extra rabbits
                complete_group = (num_of_responses / num_of_same_colour_rabbits) + 1; 
            }
            total += complete_group * (num_of_same_colour_rabbits);
        }
        
        return total;
    }
};

int main() {
    ColorfulRabbits cr;
    
    // Test case 0
    cout << cr.getMinimum({1, 1, 2, 2}) << endl; //== 5);
    
    // Test case 1
    cout << cr.getMinimum({0}) << endl; //== 1);
    
    // Test case 2
    cout << cr.getMinimum({2, 2, 44, 2, 2, 2, 444, 2, 2}) << endl; //== 499);

    // Additional test cases
    // Test case 3: Testing with all replies the same
    cout << cr.getMinimum({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) << endl; //== 8);

    // Test case 4: Testing with a single reply greater than one
    cout << cr.getMinimum({999951, 999952, 999953, 999954, 999955, 999956, 999957, 999958, 999959, 999960, 999961, 999962, 999963, 999964, 999965, 999966, 999967, 999968, 999969, 999970, 999971, 999972, 999973, 999974, 999975, 999976, 999977, 999978, 999979, 999980, 999981, 999982, 999983, 999984, 999985, 999986, 999987, 999988, 999989, 999990, 999991, 999992, 999993, 999994, 999995, 999996, 999997, 999998, 999999, 1000000}) << endl; //== 4);

    // // Test case 5: Testing with a large number of replies
    // vector<int> large = (50, 1000000);
    // cout << cr.getMinimum(large) << endl; //== 50000000);

    return 0;
}

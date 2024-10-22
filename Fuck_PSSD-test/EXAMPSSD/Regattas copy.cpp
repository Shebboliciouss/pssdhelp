#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class Regattas {
public:
    int betResult(vector<string> regattas, string ticket) {
        unordered_set<char> boats;
        int correctPredictions = 0;
        for (char c : ticket) {
            bool found = false;
            for (string& regatta : regattas) {
                if (regatta.find(c) != string::npos) {
                    if (boats.count(c) > 0 || regatta[0] != c) {
                        return -1;
                    }
                    boats.insert(c);
                    if (regatta[0] == c) {
                        correctPredictions++;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                return -1;
            }
        }
        return correctPredictions;
    }
};


int main() {

    Regattas regattas;

    // Example 0

    std::vector<std::string> races0 = {"AbX", "CdeF"};

    std::string ticket0 = "AC";

    int result0 = regattas.betResult(races0, ticket0); // Should return 2
    cout << result0 << endl;

    // Example 1

    std::vector<std::string> races1 = {"AbX", "CdeF"};

    std::string ticket1 = "CA";

    int result1 = regattas.betResult(races1, ticket1); // Should return 2
    cout << result1 << endl;

    // Example 2

    std::vector<std::string> races2 = {"AbX", "CdeF"};

    std::string ticket2 = "Cb";

    int result2 = regattas.betResult(races2, ticket2); // Should return 1
    cout << result2 << endl;

    // Example 3

    std::vector<std::string> races3 = {"AbX", "CdeF"};

    std::string ticket3 = "X";

    int result3 = regattas.betResult(races3, ticket3); // Should return 0
    cout << result3 << endl;

    // Example 4

    std::vector<std::string> races4 = {"AbX", "CdeF"};

    std::string ticket4 = "bed";

    int result4 = regattas.betResult(races4, ticket4); // Should return -1
    cout << result4 << endl;

    // Example 5

    std::vector<std::string> races5 = {"AbX", "CdeF"};

    std::string ticket5 = "dAd";

    int result5 = regattas.betResult(races5, ticket5); // Should return -1
    cout << result5 << endl;

    // Example 6

    std::vector<std::string> races6 = {"a", "b", "c", "d", "e", "f"};

    std::string ticket6 = "bead";

    int result6 = regattas.betResult(races6, ticket6); // Should return 4
    cout << result6 << endl;

    return 0;

}
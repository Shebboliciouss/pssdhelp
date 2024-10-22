#include <vector>

#include <string>

#include <unordered_set>
#include <iostream>
using namespace std;


class Regattas {

public:

    int betResult(std::vector<std::string> regattas, std::string ticket) {

        int correctPredictions = 0;

        std::unordered_set<char> selectedBoats;

        for (const std::string& race : regattas) {

            if (race.empty()) {

                return -1; // Each regatta should have at least one boat

            }

            char winner = race[0]; // The first boat in the race is the winner

            bool validRace = false;

            for (char boat : ticket) {

                if (selectedBoats.find(boat) != selectedBoats.end()) {

                    return -1; // The same boat is selected more than once

                }

                if (boat == winner) {

                    correctPredictions++;

                    validRace = true;

                }

                selectedBoats.insert(boat);

            }

            if (!validRace) {

                return 0; // The winning boat is not in the ticket

            }

            selectedBoats.clear();

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
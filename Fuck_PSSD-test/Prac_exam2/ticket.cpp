#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// class Regattas {
// public:
//     int betResult(vector<string> regattas, string ticket) {
//         int numCorrectPredictions = 0;
//         unordered_set<char> selectedBoats;
        
//         for (const string& regatta : regattas) {
//             char winner = regatta[0];
            
//             // Check if the selected boat is racing in this regatta
//             if (ticket.find(winner) == string::npos) {
//                 return -1; // Invalid ticket, boat not racing
//             }
            
//             // Check if the selected boat was already selected for this regatta
//             if (selectedBoats.find(winner) != selectedBoats.end()) {
//                 return -1; // Invalid ticket, repeated boat selection
//             }
            
//             selectedBoats.insert(winner);
//         }
        
//         for (char boat : ticket) {
//             // Check if the selected boat is racing
//             if (selectedBoats.find(boat) == selectedBoats.end()) {
//                 return -1; // Invalid ticket, boat not racing
//             }
            
//             // Check if the selected boat is already selected
//             if (selectedBoats.find(boat) != selectedBoats.end()) {
//                 return -1; // Invalid ticket, repeated boat selection
//             }
            
//             // Check if the selected boat is the winner in its corresponding regatta
//             if (regattas[boat - 'A'][0] == boat || regattas[boat - 'a'][0] == boat) {
//                 numCorrectPredictions++;
//             }
            
//             selectedBoats.insert(boat);
//         }
        
//         return numCorrectPredictions;
//     }
// };

// class Regattas {
// public:
//     int betResult(vector<string> regattas, string ticket) {
//         int numCorrectPredictions = 0;

//         unordered_set<char> racingBoats;
//         for (const string& regatta : regattas) {
//             for (char boat : regatta) {
//                 racingBoats.insert(boat);
//             }
//         }

//         unordered_set<char> selectedBoats;
//         unordered_map<char, char> winnerOfRegatta;

//         for (const string& regatta : regattas) {
//             char winner = regatta[0];
//             winnerOfRegatta[regatta[0]] = winner;

//             for (char boat : regatta) {
//                 // Check if the selected boat is racing
//                 if (racingBoats.find(boat) == racingBoats.end()) {
//                     return -1; // Invalid ticket, boat not racing
//                 }

//                 // Check if the selected boat was already selected for this regatta
//                 if (selectedBoats.find(boat) != selectedBoats.end()) {
//                     return -1; // Invalid ticket, repeated boat selection
//                 }

//                 selectedBoats.insert(boat);
//             }
//         }

//         for (char boat : ticket) {
//             // Check if the selected boat is racing
//             if (racingBoats.find(boat) == racingBoats.end()) {
//                 return -1; // Invalid ticket, boat not racing
//             }

//             // Check if the selected boat is the winner in its corresponding regatta
//             if (winnerOfRegatta.count(boat) && winnerOfRegatta[boat] == boat) {
//                 numCorrectPredictions++;
//             }
//         }

//         return numCorrectPredictions;
//     }
// };

// class Regattas {
// public:
//     int betResult(vector<string> regattas, string ticket) {
//         int numCorrectPredictions = 0;
//         unordered_set<char> selectedBoats;

//         for (const string& regatta : regattas) {
//             char winner = regatta[0];

//             // Check if the selected boat is racing in this regatta
//             if (ticket.find(winner) == string::npos) {
//                 return -1; // Invalid ticket, boat not racing
//             }

//             // Check if the selected boat was already selected for this regatta
//             if (selectedBoats.find(winner) != selectedBoats.end()) {
//                 return -1; // Invalid ticket, repeated boat selection
//             }

//             selectedBoats.insert(winner);
//         }

//         for (char boat : ticket) {
//             // Check if the selected boat is racing
//             if (selectedBoats.find(boat) == selectedBoats.end()) {
//                 return -1; // Invalid ticket, boat not racing
//             }

//             bool isWinner = false;
//             for (const string& regatta : regattas) {
//                 if (regatta[0] == boat) {
//                     isWinner = true;
//                     break;
//                 }
//             }

//             if (isWinner) {
//                 numCorrectPredictions++;
//             }
//         }

//         return numCorrectPredictions;
//     }
// };

class Regattas {
public:
    int betResult(vector<string> regattas, string ticket) {
        int numCorrectPredictions = 0;

        unordered_set<char> racingBoats;
        for (const string& regatta : regattas) {
            for (char boat : regatta) {
                racingBoats.insert(boat);
            }
        }

        unordered_set<char> selectedBoats;
        unordered_map<char, char> winnerOfRegatta;

        for (const string& regatta : regattas) {
            char winner = regatta[0];
            winnerOfRegatta[regatta[0]] = winner;

            for (char boat : regatta) {
                // Check if the selected boat is racing
                if (racingBoats.find(boat) == racingBoats.end()) {
                    return -1; // Invalid ticket, boat not racing
                }

                // Check if the selected boat was already selected for this regatta
                if (selectedBoats.find(boat) != selectedBoats.end()) {
                    return -1; // Invalid ticket, repeated boat selection
                }

                selectedBoats.insert(boat);
            }
        }

        for (char boat : ticket) {
            // Check if the selected boat is racing
            if (racingBoats.find(boat) == racingBoats.end()) {
                return -1; // Invalid ticket, boat not racing
            }

            // Check if the selected boat is the winner in its corresponding regatta
            if (winnerOfRegatta.count(boat) && winnerOfRegatta[boat] == boat) {
                numCorrectPredictions++;
            }
        }

        return numCorrectPredictions;
    }
};

int main() {
    Regattas regattasSolver;

    // Test cases
    vector<string> regattas1 = {"AbX", "CdeF"};
    string ticket1 = "AC";
    cout << "Result 1: " << regattasSolver.betResult(regattas1, ticket1) << endl; // Expected output: 2

    vector<string> regattas2 = {"AbX", "CdeF"};
    string ticket2 = "CA";
    cout << "Result 2: " << regattasSolver.betResult(regattas2, ticket2) << endl; // Expected output: 2

    vector<string> regattas3 = {"AbX", "CdeF"};
    string ticket3 = "Cb";
    cout << "Result 3: " << regattasSolver.betResult(regattas3, ticket3) << endl; // Expected output: 1

    vector<string> regattas4 = {"AbX", "CdeF"};
    string ticket4 = "X";
    cout << "Result 4: " << regattasSolver.betResult(regattas4, ticket4) << endl; // Expected output: 0

    vector<string> regattas5 = {"AbX", "CdeF"};
    string ticket5 = "bed";
    cout << "Result 5: " << regattasSolver.betResult(regattas5, ticket5) << endl; // Expected output: -1

    vector<string> regattas6 = {"AbX", "CdeF"};
    string ticket6 = "dAd";
    cout << "Result 6: " << regattasSolver.betResult(regattas6, ticket6) << endl; // Expected output: -1

    vector<string> regattas7 = {"a", "b", "c", "d", "e", "f"};
    string ticket7 = "bead";
    cout << "Result 7: " << regattasSolver.betResult(regattas7, ticket7) << endl; // Expected output: 4

    return 0;
}
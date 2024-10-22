#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Barbecue
{
public:
    	int eliminate(int n, vector<int> voter, vector<int> excluded){
            // initialing all the elements to 0
            vector<int> personCasting(n,0);
            vector<int> votingFor(n,0);

            int length = voter.size();

            for(int i = 0; i < length; i++){
                int numVotesCast = voter[i];
                int numVotesReceive = excluded[i];
                personCasting[numVotesCast]++;
                votingFor[numVotesReceive]++;
            }

            int excludingPerson = 0;
            for(int i = 1; i < n; i++){
                if(votingFor[i] > votingFor[excludingPerson] || (votingFor[i] == votingFor[excludingPerson] && personCasting[i] > personCasting[excludingPerson])){
                    excludingPerson = i;
                }
            }
            return excludingPerson;
        }
};

int main() {
    Barbecue bb;

    // Test Case 0
    {
        std::vector<int> voter = {0, 1, 2, 2};
        std::vector<int> excluded = {2, 2, 0, 1};
        int result = bb.eliminate(3, voter, excluded);
        std::cout << "Test Case 0: " << result << " (Expected: 2)" << std::endl;
    }

    // Test Case 1
    {
        std::vector<int> voter = {0, 2, 2};
        std::vector<int> excluded = {2, 0, 1};
        int result = bb.eliminate(3, voter, excluded);
        std::cout << "Test Case 1: " << result << " (Expected: 2)" << std::endl;
    }

    // Test Case 2
    {
        std::vector<int> voter = {0, 1};
        std::vector<int> excluded = {1, 0};
        int result = bb.eliminate(2, voter, excluded);
        std::cout << "Test Case 2: " << result << " (Expected: 0)" << std::endl;
    }

    // Test Case 3
    {
        std::vector<int> voter = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 19, 19, 19};
        std::vector<int> excluded = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 1, 2, 3};
        int result = bb.eliminate(20, voter, excluded);
        std::cout << "Test Case 3: " << result << " (Expected: 2)" << std::endl;
    }

    // Test Case 4
    {
        std::vector<int> voter = {4, 3, 1, 0};
        std::vector<int> excluded = {2, 2, 3, 3};
        int result = bb.eliminate(5, voter, excluded);
        std::cout << "Test Case 4: " << result << " (Expected: 3)" << std::endl;
    }

    // Test Case 5
    {
        std::vector<int> voter = {4, 5, 6, 7, 8, 9, 0, 1, 2};
        std::vector<int> excluded = {5, 6, 7, 8, 9, 0, 1, 2, 3};
        int result = bb.eliminate(10, voter, excluded);
        std::cout << "Test Case 5: " << result << " (Expected: 0)" << std::endl;
    }

    // Test Case 6
    {
        std::vector<int> voter = {1, 2, 3, 4, 5, 6, 0, 2, 3, 4, 5, 6, 0, 1, 3, 4, 5, 6, 0, 1, 2, 4, 5, 6, 0, 1, 2, 3, 5, 6, 0, 1, 2, 3, 4, 6, 0, 1, 2, 3, 4, 5};
        std::vector<int> excluded = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6};
        int result = bb.eliminate(7, voter, excluded);
        std::cout << "Test Case 6: " << result << " (Expected: 0)" << std::endl;
    }

    // Test Case 7
    {
        std::vector<int> voter = {};
        std::vector<int> excluded = {};
        int result = bb.eliminate(5, voter, excluded);
        std::cout << "Test Case 7: " << result << " (Expected: 0)" << std::endl;
    }

    return 0;
}

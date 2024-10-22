#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class PartySeats{
    public:
        vector<string> seating(vector<string> attendees){
            vector<string> boys, girls, seats;
            int n = attendees.size();
            if (n<4 || n%2 != 0){
                return seats;
            }
            for(int i = 0; i < n; i++){
                if (attendees[i].substr(n-4)=="girl"){
                    cout << "GIRL: " << attendees[i].substr(n - 4) << endl;
                    girls.push_back(attendees[i].substr(0,n-5));
                    cout << "GIRL NAME: " << attendees[i].substr(0,n-5) << endl;
                } else{
                    cout << "BOY: " << attendees[i].substr(n-3) << endl;
                    boys.push_back(attendees[i].substr(0,n-4));
                    cout << "BOY NAME: " << attendees[i].substr(0,n-4) << endl;
                }
            }

            sort(boys.begin(), boys.end());
            sort(girls.begin(), girls.end());

            if (girls.size()%2 != 0 || boys.size()%2 != 0 ){
                return seats;
            } else {
                seats.push_back("HOST");
                int num_each_side = girls.size()/2;
                for (int i = 0; i < num_each_side; i++){
                    seats.push_back(girls[i]);
                    seats.push_back(boys[i]);
                }
                seats.push_back("HOSTESS");
                for (int i = 0; i < num_each_side; i++){
                    seats.push_back(boys[i]);
                    seats.push_back(girls[i]);
                }
            }
            return seats;
            
        }
};

int main() {
    PartySeats party;

    // Test cases
    std::vector<std::string> attendees1 = {"BOB boy", "SAM girl", "DAVE boy", "JO girl"};
    std::vector<std::string> result1 = party.seating(attendees1);
    for (const std::string& person : result1) {
        std::cout << person << " ";
    }
    std::cout << std::endl;
    // { "HOST",  "JO",  "BOB",  "HOSTESS",  "DAVE",  "SAM" }

    std::vector<std::string> attendees2 = {"JOHN boy"};
    std::vector<std::string> result2 = party.seating(attendees2);
    for (const std::string& person : result2) {
        std::cout << person << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> attendees3 = {"JOHN boy", "CARLA girl"};
    std::vector<std::string> result3 = party.seating(attendees3);
    for (const std::string& person : result3) {
        std::cout << person << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> attendees4 = {"BOB boy", "SUZIE girl", "DAVE boy", "JO girl",
                                           "AL boy", "BOB boy", "CARLA girl", "DEBBIE girl"};
    std::vector<std::string> result4 = party.seating(attendees4);
    for (const std::string& person : result4) {
        std::cout << person << " ";
    }
    std::cout << std::endl;
    //{ "HOST","CARLA", "AL","DEBBIE","BOB","HOSTESS","BOB","JO","DAVE","SUZIE" }


    return 0;
}
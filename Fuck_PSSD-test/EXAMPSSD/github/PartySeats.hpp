//Received 100/100

#ifndef PARTYSEATS_HPP
#define PARTYSEATS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class PartySeats {
    public:
        vector<string> seating(vector<string> attendees) {

            int inputSize = attendees.size();

            if (inputSize % 2 != 0) {
                return {};
            } 
            
            if (inputSize < 4) {
                return {};
            }
            
            if (inputSize % 4 != 0) {
                return {};
            }

            int spacePos = 0;

            string temp = "";
            vector<string> sortedBoys;
            vector<string> sortedGirls;

            for (int i=0; i<inputSize; i++) {
                temp = attendees[i];
                spacePos = 0;
                for(int j=0; j<attendees[i].length(); j++) {
                    if(attendees[i][j] != ' ') {
                        spacePos++;
                    } else {
                        if(attendees[i].back() == 'y') {
                            temp = temp.substr(0,spacePos);
                            sortedBoys.push_back(temp);
                        } else {
                            temp = temp.substr(0,spacePos);
                            sortedGirls.push_back(temp);
                        }
                        j = attendees[i].length()-1;
                    }
                }

            }  

            if (sortedBoys.size() != sortedGirls.size()) {
                return {};
            }      
            
            vector<string> revisedSeating(inputSize+2);

            sort(sortedBoys.begin(),sortedBoys.end());
            sort(sortedGirls.begin(),sortedGirls.end());

            revisedSeating[0] = "HOST";
            int bCounter = 0;
            int gCounter = 0;
            for(int s=1; s<revisedSeating.size(); s++) {
                if(s==revisedSeating.size()/2) {
                    revisedSeating[s] = "HOSTESS";
                }
                else if(s%2 == 0) {
                    revisedSeating[s] = (sortedBoys[bCounter]);
                    bCounter++;
                } else {
                    revisedSeating[s] = (sortedGirls[gCounter]);
                    gCounter++;
                }
            }

        return revisedSeating;
        }
};

#endif
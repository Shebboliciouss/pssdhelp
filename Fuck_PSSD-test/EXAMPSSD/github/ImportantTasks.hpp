//Received 100/100

#ifndef IMPORTANTTASKS_HPP
#define IMPORTANTTASKS_HPP

#include <iostream>
#include <algorithm>
using namespace std;

class ImportantTasks {

    public:

        int maximalCost(vector<int>complexity, vector<int>computers) {

            sort(complexity.begin(),complexity.end());
            sort(computers.begin(),computers.end());

            reverse(complexity.begin(),complexity.end());
            reverse(computers.begin(),computers.end());

            vector<int> boolean_computer;
            for(int i=0; i<computers.size(); i++) {
                boolean_computer.push_back(true);
            }

            int counter=0;
            int boolean_pos=0;
            for(int j=0; j<complexity.size(); j++) {
                boolean_pos=0;
                for(int k=0; k<computers.size(); k++) {
                    if(complexity[j]<=computers[k] && boolean_computer[boolean_pos] == true) {
                        counter++;
                        boolean_computer[boolean_pos] = false;
                        break;
                    }
                    boolean_pos++;
                }
            }

        return counter;
        }

};

#endif
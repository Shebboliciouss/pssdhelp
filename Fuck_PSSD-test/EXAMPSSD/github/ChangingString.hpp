//Received 78/100

#ifndef CHANGINGSTRING_HPP
#define CHANGINGSTRING_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class ChangingString {
    public:
        int distance(string A, string B, int K) {

            vector<int> distances; 

            int distance = 0;

            for(int i=0; i<A.length(); i++) {
                distance = distance + abs(A[i] - B[i]);
                distances.push_back(abs(A[i] - B[i]));
            }

            sort(distances.begin(),distances.end());

            if(A.size() == K && A==B) {
                return K;
            }

            int j = distances.size()-1;
            int counter = 0;
            while(counter != K) {
                distance = distance - distances[j];
                if(A[j]==B[j]) {
                    distance++;
                }
                counter++;
                j--;                    
            }

            return distance;
        }
};

#endif
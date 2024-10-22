//Received 100/100

#ifndef STREETPARKING_HPP
#define STREETPARKING_HPP

#include <iostream>
#include <string>
using namespace std;

class StreetParking {
    public:
        int freeParks(string street) {
            int avail_park_spc = 0;

            for(int i=0; i<street.length(); i++) {
                if(street[i]=='-') {
                    if(street[i-1] != 'S' && street[i+1] != 'S' && street[i+1] != 'B' && street[i+2] != 'B') {
                        avail_park_spc++;
                    }
                }
            }

            return avail_park_spc;
        }
};

#endif
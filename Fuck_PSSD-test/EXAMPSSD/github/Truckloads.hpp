//Received 100/100

#ifndef TRUCKLOADS_HPP
#define TRUCKLOADS_HPP

using namespace std;

class Truckloads {
    public:
        int numTrucks(int numCrates, int loadSize) {
            if (numCrates <= loadSize) { 
                return 1;
            } else if (numCrates % 2 != 0) { //if number of crates is odd
                return numTrucks((numCrates/2)+1,loadSize) + numTrucks(numCrates/2,loadSize);
            } else return numTrucks(numCrates/2,loadSize) + numTrucks(numCrates/2,loadSize); //if even  
        }
};

#endif
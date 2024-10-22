#include <iostream>
#include <string>
using namespace std;

class StreetParking {
public:
    int freeParks(string street){
        int freeParking = 0;
        int n = street.size();
        for (int i = 0; i < n; i++){
            if (street[i] == 'D' || street[i] == 'B' || street[i] == 'S'){
                continue;
            }

            if (i < n - 1 && (street[i+1] == 'B' || street[i+1] == 'S')){
                continue;
            }

            if (i < n - 2 && street[i+2] == 'B'){
                continue;
            }

            if (i > 0 && street[i-1] == 'S'){
                continue;
            }
            freeParking++;
        }
        return freeParking;
    }
};

int main() {
    StreetParking solver;

    std::string street1 = "---B--S-D--S--";
    std::cout << "Example 1: " << solver.freeParks(street1) << std::endl; // Output: 4

    std::string street2 = "DDBDDBDDBDD";
    std::cout << "Example 2: " << solver.freeParks(street2) << std::endl; // Output: 0

    std::string street3 = "--S--S--S--S--";
    std::cout << "Example 3: " << solver.freeParks(street3) << std::endl; // Output: 2

    std::string street4 = "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D";
    std::cout << "Example 4: " << solver.freeParks(street4) << std::endl; // Output: 14

    std::string street5 = "--------------------------------------------------";
    std::cout << "Example 5: " << solver.freeParks(street5) << std::endl; // Output: 50

    return 0;
}

/*public class StreetParking{
 
    public int freeParks(String street){
        int parkingSpace = 0;
        for(int i = 0; i < street.length(); i++){
            if(street.charAt(i) == 'D') continue;
            if(street.charAt(i) == 'B') continue;
            if(street.charAt(i) == 'S') continue;
            if(i < street.length()-1 && street.charAt(i+1) == 'B') continue;
            if(i < street.length()-2 && street.charAt(i+2) == 'B') continue;
            if(i < street.length()-1 && street.charAt(i+1) == 'S') continue;
                        if(i > 0 && street.charAt(i-1) == 'S') continue;
            parkingSpace++;
        }
        return parkingSpace;
    }
}*/


/*

Problem Statement
    	
You are looking for a place to park your car on a suburban street. You can park at any position that meets the following requirements:

1.	It is not directly in front of a private driveway.
2.	It is not directly in front of a bus stop.
3.	It is not 5 meters before a bus stop.
4.	It is not 10 meters before a bus stop.
5.	It is not directly in front of a side-street.
6.	It is not 5 meters before a side-street.
7.	It is not 5 meters after a side-street.
The street will be represented as a String, where each character describes a section of the street 5 meters in length. So the first character describes the first 5 meters of the street, the second character describes the next 5 meters and so on. street will use 'D' for driveway, 'B' for bus stop, 'S' for side-street and '-' for all other sections of the street. A position is directly in front of an object if it has the same index as the object in street. A position is before an object if its index is lower than the index of the object in street. Finally, a position is after an object if its index is higher than the index of the object in street.

Given the street return the total number of possible parking spaces on that street.

 
Definition
    	
Class:	StreetParking
Method:	freeParks
Parameters:	String
Returns:	int
Method signature:	int freeParks(String street)
(be sure your method is public)
    
 
Constraints
-	street will have between 1 and 50 characters inclusive.
-	street will only contain characters 'D', 'B', 'S' and '-'.
 
Examples
0)	
    	
"---B--S-D--S--"
Returns: 4
The street looks like this:
---B--S-D--S--
^   ^    ^   ^
|   |    |   |
The arrows indicate where you are allowed to park on this street. Thus the method should return 4.
1)	
    	
"DDBDDBDDBDD"
Returns: 0
This street is full of private driveways and bus stops. You cannot park anywhere on this street. The method should return 0.
2)	
    	
"--S--S--S--S--"
Returns: 2
You can only park at the first and last positions on this street. The method should return 2.
3)	
    	
"SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D"
Returns: 14
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2006, TopCoder, Inc. All rights reserved.

*/






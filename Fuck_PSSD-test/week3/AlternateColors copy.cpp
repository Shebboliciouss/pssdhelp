#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class AlternateColors{
    public:
    string getColor(long r, long g, long b, long k){
        long minimum = min(r, min(g,b));
         if(k <= 3*minimum){
			switch(k%3){
				case(1):
					return "RED";
					break;
				case(2):
					return "GREEN";
					break;
				case(0):
					return "BLUE";
					break;
			}
		}
		k -= 3*minimum;
		r -= minimum;
		g -= minimum;
		b -= minimum;
		if(r==0){
			if(k<=2*min(g,b)){
				switch(k%2){
					case(1):
						return "GREEN";
						break;
					case(0):
						return "BLUE";
						break;
				}
			} else if(g>=b) {
				return "GREEN";
			} else {
				return "BLUE";
			}
		}
		if(g==0){
			if(k<=2*min(r,b)){
				switch(k%2){
					case(0):
						return "BLUE";
						break;
					case(1):
						return "RED";
						break;
				}
			} else if(r>=b) {
				return "RED";
			} else {
				return "BLUE";
			}
		}
		if(b==0){
			if(k<=2*min(r,g)){
				switch(k%2){
					case(1):
						return "RED";
						break;
					case(0):
						return "GREEN";
						break;
				}	
			} else if(r>=g){
				return "RED";
			} else {
				return "GREEN";
			}
		}
    }
};

int main() {
    AlternateColors ac;

    // Test case 1
    cout << "Test case 1:" << endl;
    cout << ac.getColor(1, 1, 1, 3) << endl; // Expected: "BLUE"

    // Test case 2
    cout << "Test case 2:" << endl;
    cout << ac.getColor(3, 4, 5, 4) << endl; // Expected: "RED"

    // Test case 3
    cout << "Test case 3:" << endl;
    cout << ac.getColor(7, 7, 1, 7) << endl; // Expected: "GREEN"

    // Test case 4
    cout << "Test case 4:" << endl;
    cout << ac.getColor(1000000000000, 1, 1, 1000000000002) << endl; // Expected: "RED"

    // Test case 5
    cout << "Test case 5:" << endl;
    cout << ac.getColor(653, 32, 1230, 556) << endl; // Expected: "BLUE"

    return 0;
}

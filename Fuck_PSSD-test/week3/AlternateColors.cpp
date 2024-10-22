#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class AlternateColors{
    public:
    // string getColor(long r, long g, long b, long k){
    //     vector<string> colors;
    //     int red = r;
    //     int green = g;
    //     int blue = b;
    //     long n = r+g+b;
    //     for (long i = 0; i < n; i++){
    //         if (red > 0){
    //             colors.push_back("RED");
    //             red--;
    //         }

    //         if (green > 0){
    //             colors.push_back("GREEN");
    //             green--;
    //         }

    //         if (blue > 0){
    //             colors.push_back("BLUE");
    //             blue--;
    //         }
    //     }
    //     string res = colors[k-1];
    //     return res;
    // }


    string getColor(long r, long g, long b, long k) {
        vector<pair<long, string>> color;
        if(r>0){
            color.push_back(make_pair(r, "RED"));
        } 
        if (g>0){
            color.push_back(make_pair(g, "GREEN"));
        }
        if(b>0){
            color.push_back(make_pair(b, "BLUE"));
        }
        
        long smallest = min(r, min(b, g));
        if (color.size() == 1){

            return color[0].second;
        } else if(color.size() == 2){

            smallest = min(color[0].first, color[1].first);
            if (k <= 2*smallest){
            switch(k % 2){
                case(1):
                    
                    return color[0].second;
                    break;
                case(0):
                    
                    return color[1].second;
                    break;
            }
            }
        } else {
            //smallest = min(color[0].first, min(color[1].first, color[2].first));
            if (k <= 3*smallest){
            switch(k % 3){
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
        }
      
        

        k-= 3*smallest;
        r -= smallest;
        g -= smallest;
        b -= smallest;

        // color[0].first -= smallest;
        // color[1].first -= smallest;
        // color[2].first -= smallest;
        
        return getColor(r, g, b, k);


        // if (color[0].first == 0 || color[1].first == 0|| color[2].first == 0){
        //     if (color[0].first == 0){
        //         color.erase(color.begin());
        //     } else if (color[1].first == 0){
        //         color.erase(color.begin() + 1);
        //     } else if (color[2].first == 0){
        //         color.erase(color.begin() + 2);
        //     }
        //     long small = min(color[0].first, color[1].first);


        // }

    
        
        






        // while(index >= color.size()){
        //     long n = min(color[0].first, min(color[1].first,color[2].first));
        //     for (int i = 0; i < color.size(); i++){
        //         color[i].first -= n;
        //     }
        //     index -= n*color.size();
        //     long n2 = min(color[0].first, min(color[1].first,color[2].first));
        //     vector<pair<long, string>>::iterator ptr;
        //     while (!(ptr == n2)){
        //         color.erase(ptr);
        //     }
        // }
        // string res = color[index].second();
        //return "Hello";
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

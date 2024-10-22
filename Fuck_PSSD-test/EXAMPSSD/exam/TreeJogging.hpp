#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeJogging {
public: 
    int timesAround(int N, vector<int> seen){
        int count = 0;
        int length = seen.size();
        for(int i = 0; i < length-1; i++){
            if(seen[i] >= seen[i+1]){
                count++;
            }
        }
        return count+1;
    }
};

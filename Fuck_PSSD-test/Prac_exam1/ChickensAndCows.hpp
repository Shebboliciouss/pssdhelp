#include <iostream>
#include <vector>
using namespace std;

class ChickensAndCows{
    public:
        vector<int> howMany(int heads,int legs){
            vector<int> results = {};
            int cow;
            int chic;
            if ((legs - (2*heads)) % 2 == 0){
                cow = (legs - (2*heads)) / 2;
                chic = heads - cow;
            }
            
            if (cow<0 || chic<0){
                return results;
            } else {
                results.push_back(chic);
                results.push_back(cow);
                return results;
            }
            
        }

};




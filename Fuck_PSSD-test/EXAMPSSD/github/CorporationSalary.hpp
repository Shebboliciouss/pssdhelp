//Received 100/100

#ifndef CORPORATIONSALARY_HPP
#define CORPORATIONSALARY_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CorporationSalary {
    public:
        int result = 0; 
        void recurse(int i, vector<string>rels) {
            int ans = 0; 
            for (int j = 0; j < rels.size(); j++) {
                if (rels[i][j] == 'Y') {
                    recurse(j,rels); 
                    ans = 1; 
                }
            }
            if (ans == 0) result++;  
        }

        long totalSalary(vector<string> relations) {
            result=0; 
            for (int i = 0; i < relations.size(); i++) {
                recurse(i,relations);
            }
             
            return result; 
            
        }
};

#endif
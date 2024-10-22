//Received 100/100

#ifndef MONSTERSVALLEY2_HPP
#define MONSTERSVALLEY2_HPP

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class MonstersValley2 {
    public:
    
            int recurse(int i, vector<int> level, vector<int> money, long long int health, long long int cost) {
                if(i == level.size()) {
                    return cost;
                }
                if(health >= level[i]) {
                    int nobribe = recurse(i+1,level,money,health,cost);
                    int bribe = recurse(i+1,level,money,health+level[i],cost+money[i]);
                    return (min(nobribe,bribe));
                } else return recurse(i+1,level,money,health+level[i],cost+money[i]);
            }

        	int minimumPrice(vector<int>dread, vector<int>price) {
                long long int my_scariness = dread[0];
                long long int current_cost = price[0];
                return recurse(1,dread,price,my_scariness,current_cost);
            }
};

#endif
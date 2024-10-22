#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ImportantTasks
{
public:
    int maximalCost(vector<int> complexity, vector<int> computers){
        int task = complexity.size();
        int comp = computers.size();
        sort(complexity.rbegin(), complexity.rend());
        sort(computers.rbegin(), computers.rend());
        int count = 0;
        int i = 0;
        int j = 0;
        while(j < comp && i < task){
            if(complexity[i] <= computers[j]){
                i++;
                j++;
                count++;
            }else{
                i++;
            }
        }


        // sort(complexity.begin(), complexity.end());
        // sort(computers.begin(), computers.end());
        // int task = complexity.size();
        // int comp = computers.size();
        // int count = 0;
        // for (int i = 0,j = 0; i < task && j < comp; i++,j++){
        //     (complexity[i] <= computers[j]) ? count++ : i-- ;
        // }

        
        return count;
    }
};
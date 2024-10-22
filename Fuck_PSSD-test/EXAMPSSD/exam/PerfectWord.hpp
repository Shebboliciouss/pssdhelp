#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class PerfectWord{
    public: 
        int longest (string W){
            int n = W.size();
            vector<int> word(n);
            for (int i = 0; i < n; i++){
                word[i] = W[i];
                
            }
            //vector<int> num(n);
            int count = 0;
            //int newcount = 1;
            int maxCount = 0;
            for (int i = 0; i < n-1; i++){
                if (word[i]<= word[i+1]){
                    count++;  //counting A, C, C, C, 
                    //num.push_back(word[i]);
                } else{
                    if(word[i] == word[i-1]){
                        count++;
                        // if (count > n-i){
                        //     for (int j = i+1; j < n-1; j++){
                        //         if (word[j]<= word[j+1]){
                        //             newcount++;
                        //         }
                        //     }
                        // }
                    } else{

                    }
                    if (word[i+1] <= word[i+2]){

                        continue;
                    } 
                    
                }
                maxCount = std::max(maxCount, count);
            }
            
            return maxCount+1;
        }
};

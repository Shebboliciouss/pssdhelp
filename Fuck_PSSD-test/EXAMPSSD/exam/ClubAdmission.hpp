#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ClubAdmission{
    public:
        int bestSum(vector<int> card){
            int n = card.size();
            int minnum = 100;
            for (int i = 0; i < n; i++){
                minnum=min(minnum, card[i]);
            }
            int result = 0;
            string str = std::to_string(minnum);
                if(str[0] == '9'){
                    if (str[1]== '9' ){
                        for (int j = 0; j<n; j++){
                            result += card[i];
                        }
                    }
                }
                return result;
            
        }
}
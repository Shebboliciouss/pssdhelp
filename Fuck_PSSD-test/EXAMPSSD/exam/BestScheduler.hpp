#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class BestScheduler{
public:
    int minTime(vector<int> time, vector<string> prec){
        int count = 0;
        int numY = 0;
        bool Y = false;
        int n = time.size();
        int length = prec.size();
        vector<int> v(n,0);

        for(int i = 0; i < length; i++){
            for (int j = 0; j < length; j++){
                if(prec[i][j] == 'Y'){
                    Y = true;
                    v[i] += 1;
                }
            }
        }

        int results = 0;

        for(int i = 0; i < n; i++){
            if(v[i] != 0){
                numY++;
            }
        }
        
        if(numY >= n){
            return -1;
        }

        count = accumulate(v.begin(), v.end(),0);

        if(count == 0){
            for(int i = 0; i < n; i++){
                results = max(results, time[i]);
            }
        } else{
            for(int i = 0; i < n; i++){
                if (v[i] == 0){
                    results += time[i];
                    Y = false;
                } else{
                    if (v[i+1] == 0 && Y == false && numY == 1){
                        results += time[i];
                        break;
                    } else {
                        results += time[i];
                        numY--;
                    }
                }
            }
        }

        
        return results;
    }
};

// int main(){
//     BestScheduler b;
//     cout << b.minTime({150,200,250},{"NNN","NNN","NNN"}) << endl;   //250
//     cout << b.minTime({150,200,250},{"NNN","YNN","NNN"})<< endl;   //350
//     cout << b.minTime({150,200,250},{"NYN","NNY","NNN"})<< endl;   //600
//     cout << b.minTime({150,200,250},{"NYN","NNY","YNN"})<< endl;   // -1
//     cout << b.minTime({345,335,325,350,321,620},{"NNNNNN","NNYYYY","YNNNNN","NNYNYN","NNNNNN","NNNNNN"})<< endl;   //1355
// }
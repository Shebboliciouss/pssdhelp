#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BootsExchange{
    public:
        int leastAmount(vector<int> left, vector<int> right){
            int n = left.size();
            int exchange = 0;

            //sort ascendingly
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());

            //left and right index
            int l = 0;
            int r = 0;

            while (l<n && r<n){
                if (right[r] < left[l]){
                    r++;
                    exchange++;
                } else if(left[l] < right[r]){
                    l++;
                    exchange++;
                } else if(left[l] == left[l]){
                    l++;
                    r++;
                }
            }

            // adding any leftover
            exchange += (n-l) + (n-r);

            // divide 2 to become pairs
            return exchange/2;

        }
};  

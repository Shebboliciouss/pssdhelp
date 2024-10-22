//Received 100/100

#ifndef FIBONACCIDIV2_HPP
#define FIBONACCIDIV2_HPP

#include <algorithm>
using namespace std;

class FibonacciDiv2 {

    public:

        int find(int N) {

            if(N==0 || N==1) {
                return 0;
            }

            int before_x_2 = 0;
            int before_x_1 = 1;
            
            int fib = 0;

            while(N > fib) {
                fib = before_x_1 + before_x_2;
                before_x_2 = before_x_1;
                before_x_1 = fib;

            }

            int res = min(N-before_x_2,fib-N);

        return res;                
        }
};

#endif
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

class Multiples{
public:
    int number(int min, int max, int factor){
        int result = 0;
        for (int i = min; i <= max; i++){
            if(i % factor == 0){
                result++;
            }
        }
        return result;
    }
};

// class Multiples{
// public:
//     int number(int min, int max, int factor){
//         if(min % factor == 0){
//             // Add 1 explicitly as min is divisible by factor
//             return (max/factor)-(min/factor)+1;
//         }
//         // Min is not divisible by factor
//         return (max/factor)-(min/factor);
//     }
// };
 
class Multiples {
public:
	// int number(int min, int max, int factor) {
	// 	int begin = (min % factor == 0) ? (min / factor) : (min / factor + (min > 0));
	// 	int end = (max % factor == 0) ? (max / factor) : (max / factor - (max < 0));
	// 	return end - begin + 1;
	// }


    

    int number(int min, int max, int factor) {
		int firstDivisible = 0, lastDivisible = 0;
        // the first number within the range thats divisible by the factor
        if (min % factor == 0) {
            // it gives the amount of times to add the factor number tgt to get to min value  
            firstDivisible = (min / factor);
        }else{
            // if min not evenly divisible by the factor number
            firstDivisible = (min / factor);
            // if min value is positive then +1 to get the next multiple of the factor that is greater than min;
            // example min = 7 and factor = 3, 7/3 = 2+1 = 3 which means 9/3 = 3 
            // +1 as 9 is the first number after 7 that is divisible by 3.
            if(min > 0){
               firstDivisible++; 
            }
        }

        if (max % factor == 0) {
            // if Max is evenly divisible by the factor
            // the last number within the range thats divisible by the factor
            lastDivisible = (max / factor);
        } else {
            // if max not evenly divisible by the factor number
            lastDivisible = (max / factor);
            // if max is negative then -1 to get the last multiple of the factor which is less than max value
            // example: min = -20, max = -14, factor = 5, -14/5 = -2-1 = -3 which means -15/3 = -3
            // -1 as -15 is the last number from the range that is divisible by 5
            if(max < 0){
                lastDivisible--;
            }
        }
        
        // difference between the last divisible num and the first divisible num within the range which 
        // represents the number of multiples of factor value within the range
        // +1 to include both the first and last divisible numbers within the count so that its first and last divisible numbers INCLUSIVE
        // essentially its like (-15-(-20)) gives 5 and 5/5 = 1 then +1 to include both first and last divisible number
		return lastDivisible - firstDivisible + 1;
	}
//     int number(int min, int max, int factor) {
//         // Handle the case when factor is 1
//         if (factor == 1) {
//             return max - min + 1;
//         }

//         // Calculate the first number within the range that is divisible by the factor
//         int firstDivisible = min + (factor - (min % factor)) % factor;

//         // Initialize a counter to keep track of divisible numbers
//         int count = 0;

//         // Iterate through the range with optimized steps
//         for (int i = firstDivisible; i <= max; i += factor) {
//             count++;
//         }

//         return count;
//   }
};

int main(){
    Multiples m;
    cout << m.number(0, 14, 5) << endl;
    cout << m.number(7, 24, 3) << endl;
    cout << m.number(-20, -14, 5) << endl;
    // cout << m.number(65456, 456789, 13) << endl;
    // cout << m.number(-123456, 654321, 997) << endl;
}


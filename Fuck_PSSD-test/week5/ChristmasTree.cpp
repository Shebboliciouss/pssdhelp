#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class ChristmasTree{
public: 

    // Binomial Coefficient (nCr -->  number of ways to choose a subset of r elements from a set of n distinct elements, without considering the order of selection.)
    // C(n, r) = n! / (r! * (n - r)!)
    int nCr(int n, int r){
        if (r > n){
            return 0;
        }
        if (r == 0 || r == n){
            return 1;
        }
            
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }

    long calculateWays(int level, int r, int g, int b, int currentLevel){
        // if Any of the colours are negative, then theres not enough balls for the configuration
        if (r < 0|| g < 0 || b < 0){
            return 0;
        }

        if (currentLevel == level){
            return 1;
        }

        long ways = 0;

        // currentLevel can be equally distributed for all 3 colours
        if (currentLevel % 3 == 0){
            int n = currentLevel/3;
            // calc the number of ways to arrange the balls

            // example: if currLvl = 3 then nCr(3, 3/3) --> 3C1 = 3 (num of ways of picking one colour, exp: pick red first)
            // then multiply by nCr(3-(3/3), (3-(3/3)/2 ) --> 2C1 = 2 (num of ways of picking 1 of the remaining 2 colours, exp: green and blue)
            // example 2: if currLvl = 6 --> 6C2 * 4C2 == (number of ways of choosing the 1 colour twice) * (num of ways choosing the remaining colours twice)  
            // [to make the colours are the same number]
            long numOfComb = nCr(currentLevel, n) * nCr(currentLevel-n, (currentLevel-n)/2);
            ways += calculateWays(level, r-n, g-n, b-n, currentLevel+1) * numOfComb;
        }

       if (currentLevel % 2 == 0){
            int n = currentLevel/2;
            long numOfComb = nCr(currentLevel, n);
            ways += calculateWays(level, r - n, g - n, b, currentLevel+1) * numOfFact;
			ways += calculateWays(level, r - n, g, b - n, currentLevel+1) * numOfFact;
			ways += calculateWays(level, r, g - n, b - n, currentLevel+1) * numOfFact;
       } 

        ways += calculateWays(level, r - currentLevel, g, b, currentLevel+1);
		ways += calculateWays(level, r, g - currentLevel, b, currentLevel+1);
		ways += calculateWays(level, r, g, b - currentLevel, currentLevel+1);
        return ways;

    }

    long decorationWays(int N, int red, int green, int blue){
        long totalballs = red+green+blue;
        long spaces = (N*(N+1))/2;
        if (totalballs<spaces){
            return 0;
        }
        
        long ans = calculateWays(N+1, red, green, blue, 1);
		return ans;
    }    
};

int main(){
    ChristmasTree c;
    cout<< c.decorationWays(2,1,1,1) <<endl;
    return 0;
}
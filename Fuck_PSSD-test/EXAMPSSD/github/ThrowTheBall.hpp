//Received 100/100

#ifndef THROWTHEBALL_HPP
#define THROWTHEBALL_HPP

#include <iostream>
using namespace std;

class ThrowTheBall {
    public: 
        int timesThrown(int N, int M, int L) {
            int ballPasses = 0; //this is the counter I will be using to track the number of successfull ball passes.
            int p[N]; //here I have created an array of size N (number of friends). 
            p[0] = 1; //this is for player 1, as initially the player 1 would have received the ball.

            for(int i=1; i<N; i++) { //this for loop should initialise all the values in the array (besides player 1's) to 0, as initially no one but p1 has been passed the ball yet.
                p[i] = 0;
            }

            int ballPosition = 0; //initially player 1 has the ball.

            while(p[ballPosition] != M) { //this while loop is entered only if p does not equal M
 
                if(p[ballPosition] % 2 != 0) {
                    
                    for(int a=0; a<L; a++) {
                        if(ballPosition>N-1) {
                            ballPosition=0;
                        }
                        ballPosition++;
                        if(ballPosition>N-1) {
                            ballPosition=0;
                        }
                    }
                } else {
                   
                    for(int b=0; b<L; b++) {
                         if(ballPosition<0) {
                            ballPosition=N-1;
                        }
                            ballPosition--;
                            if(ballPosition<0) {
                            ballPosition=N-1;
                        } 
                        }
                    }
                p[ballPosition]++;
                ballPasses++; //incrementing the value of successfull ball passes at the end of the while loop.
            }

            return ballPasses;
        }
};

#endif
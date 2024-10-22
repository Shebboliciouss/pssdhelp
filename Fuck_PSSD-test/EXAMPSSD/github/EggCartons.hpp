//Received 100/100

#ifndef EGGCARTONS_H
#define EGGCARTONS_H

using namespace std;

class EggCartons {
    public:
        int minCartons(int n) {

            if(n%2 != 0) {
                return -1;
            } 
            
            if(n<6) {
                return -1;
            }

            if(n==10) {
                return -1; 
            }

            int multiplesOf6[] = {6,12,18,24,30,36,42,48,54,60,66,72,78,84,90,96,102};
            int multiplesOf8[] = {8,16,24,32,40,48,56,64,72,80,88,96,104};
            int m6 = 0;
            int m8 = 0;

            int numOfCartons = 0;

            if(n%6 == 0) {
                for(int i=0; i<sizeof(multiplesOf6); i++) {
                    if(n == multiplesOf6[i]) {
                        m6 = i+1;
                        break;
                    }
                }
            } 

            if (n%8 == 0) {
                for(int j=0; j<sizeof(multiplesOf8); j++) {
                    if(n==multiplesOf8[j]) {
                        m8 = j+1;
                        break;
                    }
                }
            }

            if(m6>m8) {
                if(m8 != 0) {
                    numOfCartons = m8;
                } else numOfCartons = m6;
            } 
            
            if (m8>m6) {
                if(m6 != 0) {
                    numOfCartons = m6;
                } else numOfCartons = m8;
            }

            int modVal = 0;
            int counter = 0;

            if(n%8 != 0) {
                modVal = (n/8)+1;
                counter = modVal;
                numOfCartons = counter;
            }           
            
             if(counter>m6) {
                if(m6!= 0) {
                    numOfCartons = m6;
                } else numOfCartons = counter;
            }

            return numOfCartons;
        }
};

#endif
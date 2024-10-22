//Received 100/100

#ifndef MULTIPLES_HPP
#define MULTIPLES_HPP

class Multiples {
    public:
        int number(int min, int max, int factor) {
            int counter = 0;
            for(int i=min; i<=max; i++) {
                if(i % factor == 0) {
                    counter++;
                }
            }
            return counter;
        }
};

#endif
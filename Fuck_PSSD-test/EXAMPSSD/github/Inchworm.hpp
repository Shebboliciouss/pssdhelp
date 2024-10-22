//Received 100/100

#ifndef INCHWORM_HPP
#define INCHWORM_HPP

class Inchworm {
    public: 
        int lunchtime(int branch, int rest, int leaf) {
            int leavesConsumed = 0;
            for(int i=0; i<=branch; i++) {
                if((i % rest == 0) && (i % leaf == 0)) {
                    leavesConsumed++;
                }
            }
            return leavesConsumed;
        }
};

#endif
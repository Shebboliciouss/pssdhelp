//Received 100/100

#ifndef ROCKSTAR_HPP
#define ROCKSTAR_HPP

using namespace std;

class RockStar {
    public:
        int getNumSongs(int ff, int fs, int sf, int ss) {
            
            int songs  = 0;

            if(ff == 0 && fs == 0) {
                if(sf>0) {
                    songs = ss+1;
                } else songs = ss;
            } 
            else if(fs == 0) {
                songs = ff;
            }
            else if(fs>sf) {
                songs = ff+(2*sf)+1+ss;
            }
            else if(fs<sf) {
                songs = ff+(2*fs)+ss;
            } else songs = ff+ss+fs+ff;

            return songs;
        
        }
};

#endif
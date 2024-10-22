#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Barbecue
{
public:
    	int eliminate(int n, vector<int> voter, vector<int> excluded){
            // initialing all the elements to 0
            vector<int> personCasting(n,0);
            vector<int> votingFor(n,0);

            int length = voter.size();

    
            for(int i = 0; i < length; i++){
                int numVotesCast = voter[i];
                int numVotesReceive = excluded[i];
                personCasting[numVotesCast]++;
                votingFor[numVotesReceive]++;
            }

            int excludingPerson = 0;
            for(int i = 1; i < n; i++){
                // if number of votes receive of i is more than the number of votes receive by EX (OR)
                // if the number of votes receive is EQUAL 
                // then check whether (AND) the number votes casted by i is more than EX 
                if(votingFor[i] > votingFor[excludingPerson] || (votingFor[i] == votingFor[excludingPerson] && personCasting[i] > personCasting[excludingPerson])){
                    // then EX is change to i person
                    excludingPerson = i;
                }
            }
            return excludingPerson;
        }
};
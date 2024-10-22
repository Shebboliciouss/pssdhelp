//Received 40/100

#ifndef PREFIX_FREE_SETS_HPP
#define PREFIX_FREE_SETS_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class PrefixFreeSets {
    public:
        int maxElements(vector<string> words) {
            string substring = "";
            int temp_size = 0;
            vector<string> prefixes;
            for(int i=0; i<words.size(); i++) {
                if(!(find(prefixes.begin(),prefixes.end(),words[i]) != prefixes.end())) {
                    for(int j=0; j<words.size(); j++) {
                        substring = "";
                        temp_size = 0;
                        if(j != i) {
                            temp_size = words[j].size();
                            substring = words[i].substr(0,temp_size);
                            if(substring == words[j]) {
                                if(!(find(prefixes.begin(),prefixes.end(),words[j]) != prefixes.end())) {
                                    prefixes.push_back(words[j]);
                                }
                            }
                        }
                    }
                }
            }
            
        return (words.size()-prefixes.size());
        }
};

#endif
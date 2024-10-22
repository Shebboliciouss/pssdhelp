#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

class Arrows{
public:
    int longestArrow(string s){
        int maxcount = -1;
        int index = 0;
        int length = s.size();
        for (int i = 0; i < length; i++){
            if(s.find("<"+string(i,'-'), index)!=string::npos){
                index = s.find("<"+string(i,'-'), index);
                maxcount = std::max(maxcount, i+1);
            } else if(s.find("<"+string(i,'='), index)!=string::npos){
                index = s.find("<"+string(i,'-'), index);
                maxcount = std::max(maxcount, i+1);

            } else if(s.find(string(i,'-')+">", index)!=string::npos){
                maxcount = std::max(maxcount, i+1);
            } else if(s.find(string(i,'=')+">", index)!=string::npos){
                maxcount = std::max(maxcount, i+1);
            }
        }
        return maxcount;
    }
};

class Arrows{
public:
    int longestArrow(string s){
        int maxcount = -1;
        int length = s.size();
        //iterate through the string 
        for (int i = 0; i < length; i++){
            if (s[i] == '>'){
                // have to check before this index 'i'
                maxcount = std::max(maxcount,1);   // 1 for counting the '>'
                // if its '-' then use this for loop
                for (int j = i-1; j >= 0 && (s[j] == '-'); j--){
                    // i-j would give the length of '-' behind '>' and +1 for counting the '>'
                    maxcount = std::max(maxcount, (i-j)+1); 
                }
                // if its '=' then use this for loop
                for (int j = i-1; j >= 0 && (s[j] == '='); j--){
                    maxcount = std::max(maxcount, (i-j)+1);
                }
            } else if (s[i] == '<'){
                // check after the index 'i'
                maxcount = std::max(maxcount,1);  // 1 for counting the '<'
                // if its '-' then use this for loop
                for (int j = i+1; j < length && (s[j] == '-'); j++){
                    // j-i would give the length of '-' in front of '<' and +1 for counting the '<'
                    maxcount = std::max(maxcount, j-i+1);         
                }
                // if its '=' then use this for loop
                for (int j = i+1; j < length && (s[j] == '='); j++){
                    maxcount = std::max(maxcount, j-i+1);
                }
            }
        }
        return maxcount;
    }
};

int main() {
  Arrows arrows;

  // Test cases
  string test1 = "=========>";
  string test2 = "<<<<<<<<<<";
  string test3 = "----==-";
  string test4 = "<----=====>";

  cout << "Test 1: " << arrows.longestArrow(test1) << " (Expected: 10)" << endl;
  cout << "Test 2: " << arrows.longestArrow(test2) << " (Expected: 1)" << endl;
  cout << "Test 3: " << arrows.longestArrow(test3) << " (Expected: -1)" << endl;
  cout << "Test 4: " << arrows.longestArrow(test4) << " (Expected: 6)" << endl;

  return 0;
}


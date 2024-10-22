#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class PerfectWord{
    public: 
        int longest (string W){
            bool order = isAlphabaticOrder(W);
            
        }
};
 
// Function that checks whether
// the string is in alphabetical
// order or not
bool isAlphabaticOrder(string s)
{
    // length of the string
    int n = s.length();
 
    // create a character array
    // of the length of the string
    char c[n];
 
    // assign the string
    // to character array
    for (int i = 0; i < n; i++) {
        c[i] = s[i];
    }
 
    // sort the character array
    sort(c, c + n);
 
    // check if the character array
    // is equal to the string or not
    for (int i = 0; i < n; i++)
        if (c[i] != s[i])
            return false;
    
    return true;   
}
 
// Driver code
int main() {
    PerfectWord p;
    
    std::cout << p.longest("ABCDEFG")<< std::endl; // Output: 7
    
    std::cout << p.longest("GFEDCBA") << std::endl; // Output: 1
    
    
    std::cout << p.longest("ACBB") << std::endl; // Output: 3

    std::cout << p.longest("ACCCCBB") << std::endl; // Output: 5



    std::cout << p.longest("ACCBBB") << std::endl; // Output: 4
    std::cout << p.longest("ACCCCBBC") << std::endl; // Output: 6
    return 0;
}
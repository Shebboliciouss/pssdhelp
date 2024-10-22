#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;
 
class StrangeComputer {
public:
//   int setMemory(string m) {
//     int c='0';
//     int n=0;
//     for(int i=0; i<m.size(); i++){
//         if(m[i]!=c) { 
//             c=m[i]; 
//             n++; 
//         }
//     }
//     return n;
  
//   }

// int setMemory(string mem) {
//         int operations = 0;
//         char lastBit = '0';
//         for (char bit : mem) {
//             if (bit != lastBit) {
//                 operations++;
//                 lastBit = bit;
//             }
//         }
//         return operations;
//     }


    

    // int setMemory(string mem){
    //     // Remove consecutive duplicates
    //     auto ptr = unique(mem.begin(), mem.end());
    
    //     // Resize mem to new size
    //     mem.resize(ptr - mem.begin());
    //     // store the number of characters processed by the conversion function
    //     std::string::size_type sz = 0;   // alias of size_t
    //     unsigned long long mem_num = std::stoull(mem, &sz ,2);
    //     if(mem_num == 0){
    //         return 0;
    //     }

    //     //cout << "SZ: " << sz << endl;

    //     int num_oprations = 0;
    //     char mem_char = '0';
    //     for(char bits : mem){
    //         if(bits != mem_char){
    //             mem_char = bits;
    //             num_oprations++;
    //         }
    //     }
    //     return num_oprations;
    // }






//     int setMemory(std::string mem) {
//     // Remove consecutive duplicates in mem
//     auto newEnd = std::unique(mem.begin(), mem.end());
    
//     // Resize mem to new size
//     mem.resize(newEnd - mem.begin());

//     // Calculate number of operations
//     int operations = mem.size() - 1;
    
//     // If first bit is 1, add 1 to operations
//     if (mem[0] == '1') {
//         operations++;
//     }

//     return operations;
// }
//     int setMemory(string mem) {
// 		mem.resize(unique(mem.begin(), mem.end()) - mem.begin());
        
//         return ((int)mem.size()-1) + (mem[0]=='1');
        
// 	}



int setMemory(string mem) {
    // Remove consecutive duplicates
    auto ptr = unique(mem.begin(), mem.end());

    // Resize mem to new size
    mem.resize(ptr - mem.begin());

    // store the number of characters processed by the conversion function
    std::string::size_type sz = 0;  // alias of size_t

    // change string to int
    unsigned long long mem_num = std::stoull(mem, &sz, 2);

    if (mem_num == 0) {
      return 0;
    }

    if(mem[0] == '1'){
        sz += 1;
    } 

    return sz-1;


    // cout << "SZ: " << sz << endl;


    // int num_oprations = 0;
    // // Initialise default memory value '0'
    // char mem_char = '0';
    // // Iterate through the string
    // for (char bits : mem) {
    // // If not the same then have to switch value so increase the number of operations    
    //   if (bits != mem_char) {
    //     mem_char = bits;
    //     num_oprations++;
    //   }
    // }
    // return num_oprations;
  }




};

int main(){
    StrangeComputer s;
    cout << s.setMemory("0011") << endl;       // Return: 1
    cout << s.setMemory("000") << endl;         // Return: 0
    cout << s.setMemory("0100") << endl;        // Return: 2
    cout << s.setMemory("111000111") << endl;       // Return: 3
    cout << s.setMemory("0") << endl;       // Return: 0
    cout << s.setMemory("1") << endl;       // Return: 1
    cout << s.setMemory("00") << endl;      // Return: 0
    cout << s.setMemory("11") << endl;      // Return: 1
    cout << s.setMemory("01") << endl;      // Return: 1
    cout << s.setMemory("10") << endl;      // Return: 2
    cout << s.setMemory("00000000000000000000000000000000000000000000000000") << endl;      // Return: 0
    cout << s.setMemory("10000000000000000000000000000000000000000000000000") << endl;      // Return: 2
    cout << s.setMemory("00000000000000000000000000000000000000000000000001") << endl;      // Return: 1
    cout << s.setMemory("10101010101010101010101010101010101010101010101010") << endl;      // Return: 50
    cout << s.setMemory("01010101010101010101010101010101010101010101010101") << endl;      // Return: 49
    cout << s.setMemory("01010101010101010101010101010101010101010101010111") << endl;      // Return: 47
    cout << s.setMemory("11111111111111111111111111111111111111111111111111") << endl;      // Return: 1
    cout << s.setMemory("11111111111111111111111111111111111111111111111110") << endl;      // Return: 2
    cout << s.setMemory("01111111111111111111111111111111111111111111111111") << endl;      // Return: 1
    cout << s.setMemory("01111001101011000001011000111100011101011110100101") << endl;      // Return: 25
    return 0;
}
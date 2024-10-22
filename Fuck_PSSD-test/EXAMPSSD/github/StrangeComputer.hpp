//Received 100/100

#ifndef STRANGECOMPUTER_HPP
#define STRANGECOMPUTER_HPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StrangeComputer {
    public:
        int setMemory(string mem) {

            string initial_memory = "";
            int mem_size = mem.length();

            for(int i=0; i<mem_size; i++) {
                initial_memory = initial_memory + "0";
            }

            if(initial_memory == mem) return 0;

            int operations = 0;
            int looper = 0;

            while(initial_memory != mem) {
                if(initial_memory[looper] != mem[looper]) {
                    operations++;
                    if (mem[looper] == '0') {
                        for(int k=looper; k<mem_size; k++) {
                            initial_memory[k] = '0';
                        }
                    } else for(int k=looper; k<mem_size; k++) {
                            initial_memory[k] = '1';
                            }
                }
                looper++;
            }
        return operations;
        }
};

#endif
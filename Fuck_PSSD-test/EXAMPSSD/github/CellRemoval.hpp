//Received 100/100

#ifndef CELLREMOVAL_HPP
#define CELLREMOVAL_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class CellRemoval {
	
	public:

		int dCell;
		int result=0;

		int deleter(unordered_map<int,vector<int>>cells,int current_node,vector<bool> visited) {

			visited[current_node] = true;
  
    		if(current_node == dCell) {
    			return 0;
    		}

    		if(cells[current_node].empty()) {
    			result++;
				return result;
    		}

			int temp=0;

			for (auto i : cells[current_node]) {
        		if (visited[i] == false) {
            		temp += deleter(cells,i,visited);
				}
			}

			return temp;
    	}
		

		int cellsLeft(vector<int> parent, int deletedCell) {
			
			dCell = deletedCell;
			result = 0;
			int root=0;
			unordered_map<int,vector<int>> cells;

			for(int i=0; i<parent.size(); i++) {
				if(parent[i] != -1) {
					cells[parent[i]].push_back(i);
				}
				if(parent[i] == -1) {
					root = i;
				}
			}

			vector<bool> visited(parent.size());
			for(int j=0; j<parent.size(); j++) {
				visited[j] = false;
			}

			int temp2 = deleter(cells,root,visited);
	
		return result;
		}

};

#endif
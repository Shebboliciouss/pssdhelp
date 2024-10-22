#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <unordered_set>

using namespace std;

class ErdosNumber {
public:
    vector<string> calculateNumbers(vector<string> publications) {
        // this represents an adjacent list of co-authorship graph --> each author is set as a key and the value is a set of other authors that they co-authored
        map<string, unordered_set<string>> graph;
        // store the erdos numbers for each author
        map<string, int> erdosNum;
        // Breadth first search (BFS) for graph 
        queue<string> que;

        // iterate through each publications 
        for (auto pub : publications) {
            // separate the author name in the publications
            istringstream streaming(pub);
            // store each author name into the authors vector
            vector<string> authors;
            // Read each author name and store in the authors vector
            string writer;
            while (streaming >> writer) {
                authors.push_back(writer);
                graph[writer];  // Add all authors to the graph
            }

            // example authors vector {A, B, C}
            for (auto a : authors) {
                // graph[A], graph[B], graph[C]
                for (auto co : authors) {
                    // if not the same name then its a co-author
                    if (a != co) {
                        graph[a].insert(co);  // create edges between all pairs of co-authors in each publication 
                    }
                }
            }
        }

        // set ERDOS to erdos number 0 and push it to queue to start BFS
        erdosNum["ERDOS"] = 0;
        que.push("ERDOS");


        // BFS algorithm for graph 
        // while the queue is NOT empty, if empty then theres no more authors to visit
        while (!que.empty()) {
            // store the front element of the queue
            string currentAuthor = que.front();
            // delete the first element of the queue
            que.pop();
            // iterates over all their co-authors./ edges of the current node of the graph
            for (auto coauthor : graph[currentAuthor]) {
                // if co-author hasnt been assigned an Erdos number, 
                if (erdosNum.count(coauthor) == 0) {
                    // the co-author is assigned an erdos number one greater than the current author's Erdos number
                    erdosNum[coauthor] = erdosNum[currentAuthor] + 1;
                    // then add their name into the queue
                    que.push(coauthor);
                }
            }
        }

        
        vector<string> ans;
        // iterates over all the authors in the graph
        for (auto author : graph) {
            // if the authors is assigned to a erdos number 
            if (erdosNum.count(author.first) == 1) {
                // add the name and number into the vector 
                ans.push_back(author.first + " " + to_string(erdosNum[author.first]));
            } else {
                // if dont have number just push the name
                ans.push_back(author.first);
            }
        }
        // sort the vector lexicographically 
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};
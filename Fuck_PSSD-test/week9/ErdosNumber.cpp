#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iterator>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

class ErdosNumber {
public:
    vector<string> calculateNumbers(vector<string> publications) {
        // this represents an adjacent list of co-authorship graph --> each author is set as a key and the value is a set of other authors that they co-authored
        map<string, unordered_set<string>> graph;
        // store the erdos numbers for each author
        //map<string, int> erdosNumbers;
        vector<pair<string, int>> ErdosNum;
        // Breadth first search (BFS) for graph 
        queue<string> BFS;

        // iterate through each publications 
        for (auto publication : publications) {
            // separate the author name in the publication
            istringstream streaming(publication);
            // store each author name into the authors vector
            vector<string> authors;
            // Read each author name and store in the authors vector
            string writer;
            while (streaming >> writer) {
                authors.push_back(writer);
                graph[writer];
            }

            // example authors vector {A, B, C}
            for (auto author : authors) {
                // graph[A], graph[B], graph[C]
                  // Add all authors to the graph
                for (auto coauthor : authors) {
                    // if not the same name then its a co-author
                    if (author != coauthor) {
                        graph[author].insert(coauthor);  // create edges between all pairs of co-authors in each publication 
                    }
                }
            }
        }

        // set ERDOS to erdos number 0 and push it to queue to start BFS
        // ErdosNum["ERDOS"] = 0;
        ErdosNum.push_back(make_pair("ERDOS",0));
        BFS.push("ERDOS");


        // BFS algorithm for graph 
        // while the queue is NOT empty, if empty then theres no more authors to visit
        while (!BFS.empty()) {
            // store the front element of the queue
            string current = BFS.front();
            // delete the first element of the queue
            BFS.pop();
            // iterates over all their co-authors./ edges of the current node of the graph
            for (auto coauthor : graph[current]) {
                bool found = false;
                for (auto num : ErdosNum){
                    // iterates through the vector and if num.first is the same as name as the coauthor
                    if(num.first == coauthor){
                        // then the erdos value is already computed
                        found = true;
                        break;
                    }
                }
                // checks if Erdos number of the neighbour has already been calculated
                if(found == false){
                    int currEnum;
                    for (auto num : ErdosNum){
                        if(num.first == current){
                            currEnum = num.second;
                            break;
                        }
                    }
                    ErdosNum.push_back(make_pair(coauthor, currEnum + 1));
                    BFS.push(coauthor);
                }
            }
        }
        sort(ErdosNum.begin(), ErdosNum.end());
        return ErdosNum;

        // // creates a results vector that iterates over all the authors in the graph 
        // vector<string> result;
        // for (auto author : graph) {
        //     // if the authors is assigned to a erdos number 
        //     if (erdosNumbers.count(author.first)) {
        //         // add the name and number intp the vector 
        //         result.push_back(author.first + " " + to_string(erdosNumbers[author.first]));
        //     } else {
        //         // if dont have number just push the name
        //         result.push_back(author.first);
        //     }
        // }
        // // sort the vector lexicographically 
        // sort(result.begin(), result.end());
        // return result;
    }
};



int main() {
    ErdosNumber en;
    vector<string> publications = {"ERDOS B", "A B C", "B A E", "D F"};
    vector<string> result = en.calculateNumbers(publications);
    for (const auto& s : result) {
        cout << s << endl;
    }
    cout <<"----------------------" << endl;
    vector<string> publications1 = {"ERDOS"};
    vector<string> result1 = en.calculateNumbers(publications1);
    for (const auto& s : result1) {
        cout << s << endl;
    }
    cout <<"----------------------" << endl;
    vector<string> publications2 = {"KLEITMAN LANDER", "ERDOS KLEITMAN"};
    vector<string> result2 = en.calculateNumbers(publications2);
    for (const auto& s : result2) {
        cout << s << endl;
    }
    cout <<"----------------------" << endl;
    vector<string> publications3 = {"ERDOS A", "A B", "B AA C"};
    vector<string> result3 = en.calculateNumbers(publications3);
    for (const auto& s : result3) {
        cout << s << endl;
    }
    cout <<"----------------------" << endl;
    vector<string> publications4 = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
    vector<string> result4 = en.calculateNumbers(publications4);
    for (const auto& s : result4) {
        cout << s << endl;
    }
    cout <<"----------------------" << endl;
    vector<string> publications5 = {"ERDOS ARRARRARRARRARRARRARRARRARRARRARRARRARRARRAR", "ARRARRARRARRARRARRARRARRARRARRARRARRARRARRAR JOHN", "ERRERRERRERRERRERRERRERRERRERRERRERRERRERRERRERROR"};
    vector<string> result5 = en.calculateNumbers(publications5);
    for (const auto& s : result5) {
        cout << s << endl;
    }
    cout <<"----------------------" << endl;
    return 0;
}


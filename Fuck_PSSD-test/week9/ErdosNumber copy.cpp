#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

class ErdosNumber {
public:
    std::vector<std::string> calculateNumbers(std::vector<std::string> publications) {
        // this represents an adjacent list of co-authorship graph --> each author is set as a key and the value is a set of other authors that they co-authored
        std::unordered_map<std::string, std::unordered_set<std::string>> graph;
        // store the erdos numbers for each author
        std::unordered_map<std::string, int> erdosNumbers;
        // Breadth first search (BFS) for graph 
        std::queue<std::string> q;

        // iterate through each publications 
        for (const auto& publication : publications) {
            // separate the author name in the publication
            std::istringstream streaming(publication);
            // store each author name into the authors vector
            std::vector<std::string> authors;
            // Read each author name and store in the authors vector
            std::string writer;
            while (streaming >> writer) {
                authors.push_back(writer);
            }

            // example authors vector {A, B, C}
            for (const auto& author : authors) {
                // graph[A], graph[B], graph[C]
                graph[author];  // Add all authors to the graph
                for (const auto& coauthor : authors) {
                    // if not the same name then its a co-author
                    if (author != coauthor) {
                        graph[author].insert(coauthor);  // create edges between all pairs of co-authors in each publication 
                    }
                }
            }
        }

        // // Print the collaboration graph
        // for (const auto& entry : graph) {
        //     std::cout << entry.first << " is connected to: ";
        //     for (const auto& coauthor : entry.second) {
        //         std::cout << coauthor << " ";
        //     }
        //     std::cout << std::endl;
        // }

        // set ERDOS to erdos number 0 and push it to queue to start BFS
        erdosNumbers["ERDOS"] = 0;
        q.push("ERDOS");

        // BFS algorithm for graph 
        // while the queue is NOT empty, if empty then theres no more authors to visit
        while (!q.empty()) {
             // Each iteration it removes an author from the front of the queue
            // store the front element of the queue
            std::string current = q.front();
            // delete the first element of the queue
            q.pop();
            // iterates over all their co-authors./ edges
            for (const auto& neighbor : graph[current]) {
                // if co-author hasnt been assigned an Erdos number, 
                if (erdosNumbers.count(neighbor) == 0) {
                    // the co-author is assigned an erdos number one greater than the current author's Erdos number
                    erdosNumbers[neighbor] = erdosNumbers[current] + 1;
                    // then add their name into the queue
                    q.push(neighbor);
                }
            }
        }

        // creates a results vector that iterates over all the authors in the graph 
        std::vector<std::string> result;
        for (const auto& author : graph) {
            // if the authors is assigned to a erdos number 
            if (erdosNumbers.count(author.first) == 1) {
                // add the name and number intp the vector 
                result.push_back(author.first + " " + std::to_string(erdosNumbers[author.first]));
            } else {
                // if dont have number just push the name
                result.push_back(author.first);
            }
        }
        // sort the vector lexicographically 
        std::sort(result.begin(), result.end());
        return result;
    }
};



int main() {
    ErdosNumber en;
    std::vector<std::string> publications = {"ERDOS B", "A B C", "B A E", "D F"};
    std::vector<std::string> result = en.calculateNumbers(publications);
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
    std::cout <<"----------------------" << std::endl;
    std::vector<std::string> publications1 = {"ERDOS"};
    std::vector<std::string> result1 = en.calculateNumbers(publications1);
    for (const auto& s : result1) {
        std::cout << s << std::endl;
    }
    std::cout <<"----------------------" << std::endl;
    std::vector<std::string> publications2 = {"KLEITMAN LANDER", "ERDOS KLEITMAN"};
    std::vector<std::string> result2 = en.calculateNumbers(publications2);
    for (const auto& s : result2) {
        std::cout << s << std::endl;
    }
    std::cout <<"----------------------" << std::endl;
    std::vector<std::string> publications3 = {"ERDOS A", "A B", "B AA C"};
    std::vector<std::string> result3 = en.calculateNumbers(publications3);
    for (const auto& s : result3) {
        std::cout << s << std::endl;
    }
    std::cout <<"----------------------" << std::endl;
    std::vector<std::string> publications4 = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
    std::vector<std::string> result4 = en.calculateNumbers(publications4);
    for (const auto& s : result4) {
        std::cout << s << std::endl;
    }
    std::cout <<"----------------------" << std::endl;
    std::vector<std::string> publications5 = {"ERDOS ARRARRARRARRARRARRARRARRARRARRARRARRARRARRAR", "ARRARRARRARRARRARRARRARRARRARRARRARRARRARRAR JOHN", "ERRERRERRERRERRERRERRERRERRERRERRERRERRERRERRERROR"};
    std::vector<std::string> result5 = en.calculateNumbers(publications5);
    for (const auto& s : result5) {
        std::cout << s << std::endl;
    }
    std::cout <<"----------------------" << std::endl;
    return 0;
}


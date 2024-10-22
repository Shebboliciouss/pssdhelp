#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>

struct Neighbor {
    int row;
    int col;
};

std::vector<Neighbor> checkNeighbors(const std::vector<std::vector<int>>& matrix, int row, int col) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    std::vector<Neighbor> neighbors;
    
    // Check top neighbor if it exists
    if (row > 0) {
        neighbors.push_back({row - 1, col});
    }
    
    // Check bottom neighbor if it exists
    if (row < rows - 1) {
        neighbors.push_back({row + 1, col});
    }
    
    // Check left neighbor if it exists
    if (col > 0) {
        neighbors.push_back({row, col - 1});
    }
    
    // Check right neighbor if it exists
    if (col < cols - 1) {
        neighbors.push_back({row, col + 1});
    }
    
    return neighbors;
}

int main() {
    // Example 2D matrix
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {0}
    };
    
    int row_index = 0;  // Row index of the element
    int col_index = 0;  // Column index of the element
    
    std::vector<Neighbor> neighbors = checkNeighbors(matrix, row_index, col_index);
    
    std::cout << "Neighbor indices:";
    for (const Neighbor& neighbor : neighbors) {
        std::cout << " (" << neighbor.row << ", " << neighbor.col << ")";
    }
    std::cout << std::endl;

    return 0;
}


// std::vector<int> checkNeighbors(const std::vector<std::vector<int>>& matrix, int row, int col) {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
    
//     std::vector<int> neighbors;
    
//     // Check top neighbor if it exists
//     if (row > 0) {
//         neighbors.push_back(matrix[row - 1][col]);
//     }
    
//     // Check bottom neighbor if it exists
//     if (row < rows - 1) {
//         neighbors.push_back(matrix[row + 1][col]);
//     }
    
//     // Check left neighbor if it exists
//     if (col > 0) {
//         neighbors.push_back(matrix[row][col - 1]);
//     }
    
//     // Check right neighbor if it exists
//     if (col < cols - 1) {
//         neighbors.push_back(matrix[row][col + 1]);
//     }
    
//     return neighbors;
// }

// int main() {
//     // Example 2D matrix
//     std::vector<std::vector<int>> matrix = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9},
//         {0}
//     };
    
//     int row_index = 0;  // Row index of the element
//     int col_index = 0;  // Column index of the element
    
//     std::vector<int> neighbors = checkNeighbors(matrix, row_index, col_index);
    
//     std::cout << "Neighbors:";
//     for (int neighbor : neighbors) {
//         std::cout << " " << neighbor;
//     }
//     std::cout << std::endl;

//     return 0;
// }




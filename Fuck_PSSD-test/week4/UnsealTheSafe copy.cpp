#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

class UnsealTheSafe{
    public:
    long countPasswords(int N){

         map<int, vector<int>> keypad = {
            // key, value {neibouring keys};
            {0, {7}},
            {1, {2, 4}},
            {2, {1, 3, 5}},
            {3, {2, 6}},
            {4, {1, 5, 7}},
            {5, {2, 4, 6, 8}},
            {6, {3, 5, 9}},
            {7, {4, 8, 0}},
            {8, {5, 7, 9}},
            {9, {6, 8}}
        };
        
        // int **dp = new int*[N+1];
        // for(int i = 0; i < N+1; i++){
        //     dp[i] = new int[10];
        // }

        // for (int i = 0; i <= N; i++){
        //     for (int j = 0; j < 10;j++){
        //         dp[i][j] = 0;
        //     }
        // }

        // for (int i = 0; i < 10; i++){
        //     dp[1][i] = 1;
        // }

        // for (int i = 2; i <= N; i++){
        //     for (int j = 0; j < 10;j++){
        //         int count = checkNeighbors(j, i);
        //         dp[i][j] += count;
        //     }
        // }

    //     for (int i = 2; i <= N; i++){
    //         // Set the latest known combination for the current key press.
    //         // 0 can only come from 7
    //         dp[i][0] = dp[i-1][7];
    //         // 1 can come from 2 and 4.
    //         dp[i][1] = dp[i-1][2] + dp[i-1][4];
    //         // 2 can come from 1, 3 and 5.
    //         dp[i][2] = dp[i-1][1] + dp[i-1][3] + dp[i-1][5];
    //         // 3 can come from 2 and 6.
    //         dp[i][3] = dp[i-1][2] + dp[i-1][6];
    //         // 4 can come from 1, 5 and 7.
    //         dp[i][4] = dp[i-1][1] + dp[i-1][5] + dp[i-1][7];
    //         // 5 can come from 2, 4, 6 and 8.
    //         dp[i][5] = dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8];
    //         // 6 can come from 3, 5 and 9.
    //         dp[i][6] = dp[i-1][3] + dp[i-1][5] + dp[i-1][9];
    //         // 7 can come from 4, 8 and 0.
    //         dp[i][7] = dp[i-1][4] + dp[i-1][8] + dp[i-1][0];
    //         // 8 can come from 5, 7 and 9.
    //         dp[i][8] = dp[i-1][5] + dp[i-1][7] + dp[i-1][9];
    //         // 9 can come from 6 and 8.
    //         dp[i][9] = dp[i-1][6] + dp[i-1][8];
    //     }
        map<pair<int, int>, long long> data;
        // long long total_comb_pass = 0;
        // for (int i = 0; i < 10; i++){
        //     total_comb_pass += dp[N][i];
        // }
        long long total_comb_pass = 0;
        for (int i = 0; i < 10; i++){

            // calc {2, 0}, {2,1}, {2,2}, {2,3} .....{2,9} if N = 2
            total_comb_pass += checkNeighbors(N, i, keypad, data);
        }

        // for(int i = 0; i < N+1; i++){
        //     delete[] dp[i];
        //     delete[] dp;
        // }

        return total_comb_pass;

    }

    long long checkNeighbors(int i, int j, map<int, vector<int>>& keypad, map<pair<int, int>, long long>& data){
        
        // vector<int> neighbors;
        // switch (K){
        //     case 0: 
        //         neighbors.push_back(7);
        //         //count = 1;
        //         break;
        //     case 1:
        //         neighbors.push_back(2);
        //         neighbors.push_back(4);
        //         //count = 2;
        //         break;
        //     case 2:
        //         neighbors.push_back(1);
        //         neighbors.push_back(3);
        //         neighbors.push_back(5);
        //         //count = 3;
        //         break;  
        //     case 3:
        //         neighbors.push_back(2);
        //         neighbors.push_back(6);
        //         //count = 2;
        //         break;
        //     case 4:
        //         neighbors.push_back(1);
        //         neighbors.push_back(5);
        //         neighbors.push_back(7);
        //         //count = 3;
        //         break;
        //     case 5:
        //         neighbors.push_back(2);
        //         neighbors.push_back(4);
        //         neighbors.push_back(6);
        //         neighbors.push_back(8);
        //         //count = 4;
        //         break;
        //     case 9:
        //         neighbors.push_back(6);
        //         neighbors.push_back(8);
        //         //count = 2;
        //         break;
            
            
        //     case 6:
        //         neighbors.push_back(3);
        //         neighbors.push_back(5);
        //         neighbors.push_back(9);
        //         //count = 3;
        //         break;
        //     case 7: 
        //         neighbors.push_back(4);
        //         neighbors.push_back(8);
        //         neighbors.push_back(0);
        //         //count = 3;
        //         break;
        //     case 8:
        //         neighbors.push_back(5);
        //         neighbors.push_back(7);
        //         neighbors.push_back(9);
        //         //count = 3;
        //         break;

            

        // }

    // int n = neighbors.size();
    // long long count = 0;
    // if (i>2){
    //     i--;
    //     for (int k = 0; k < n; k++){  
    //        long long recursiveCount = checkNeighbors(neighbors[k], i);
    //        count+=recursiveCount;
    //     }
    // } else{
    //     count = n;
    // }

    if (i == 1){
        return 1;
    }

    // if the pair(i, j) is already calculate in data map then return the value 
    // This is to prevent redundant calculations
    if(data.find({i,j}) != data.end()){
        return data[{i, j}];
    }

    // Range based loop that iterates through the neighbouring numbers 
    // for that value, keypad[j] 
    // Example: keypad[2] = get the value at key=2, which is {1, 3, 5}
    // so every loop k changes --> k = 1, --> k = 3, --> k = 5;
    long long count = 0;
    for (auto k : keypad[j]){
        count += checkNeighbors(i-1, k, keypad, data);
    }

    // After the loop data map at (i,j) stores the count
    // Memoization 
    data[{i, j}] = count;
    return count;
    
    }
};

// class UnsealTheSafe {
// public:
//     long countPasswords(int N) {
//         map<int, vector<int>> keypad = {
//             // key, value {neibouring keys};
//             {0, {7}},
//             {1, {2, 4}},
//             {2, {1, 3, 5}},
//             {3, {2, 6}},
//             {4, {1, 5, 7}},
//             {5, {2, 4, 6, 8}},
//             {6, {3, 5, 9}},
//             {7, {4, 8, 0}},
//             {8, {5, 7, 9}},
//             {9, {6, 8}}
//         };

//         map<pair<int, int>, long long> data;
//         long long total_comb_pass = 0;

//         for (int i = 0; i < 10; i++){
//             total_comb_pass += countPasswordsRecursive(N, i, keypad, data);
//         }

//         return total_comb_pass;
//     }

//     long long countPasswordsRecursive(int i, int j, map<int, vector<int>>& keypad, map<pair<int, int>, long long>& data) {
        

//         if (i == 1) {
//             return 1;
//         }

//         if (data.find({i, j}) != data.end()) {
//             return data[{i, j}];
//         }

//         long long count = 0;
//         for (int neighbor : keypad[j]) {
//             count += countPasswordsRecursive(i - 1, neighbor, keypad, data);
//         }

//         data[{i, j}] = count;
//         return count;
//     }
// };


int main() {
    UnsealTheSafe solver;
    //cout << solver.checkNeighbors(1,2) << endl;
    cout<< "2 : " << solver.countPasswords(2) << endl;
    cout<< "3 : " << solver.countPasswords(3) << endl;
    cout<< "4 : " << solver.countPasswords(4) << endl;
    cout<< "5 : " << solver.countPasswords(5) << endl;
    cout<< "6 : " << solver.countPasswords(6) << endl;
    cout<< "7 : " << solver.countPasswords(7) << endl;
    cout<< "8 : " << solver.countPasswords(8) << endl;
    cout<< "9 : " << solver.countPasswords(9) << endl;
    cout<< "10 : " << solver.countPasswords(10) << endl;
    cout<< "11 : " << solver.countPasswords(11) << endl;
    cout<< "12 : " <<solver.countPasswords(12) << endl;
    cout<< "13 : " << solver.countPasswords(13) << endl;
    cout<< "14 : " << solver.countPasswords(14) << endl;
    cout<< "15 : " << solver.countPasswords(15) << endl;
    cout<< "16 : " << solver.countPasswords(16) << endl;
    cout<< "17 : " << solver.countPasswords(17) << endl;
    cout<< "18 : " << solver.countPasswords(18) << endl;
    cout<< "19 : " << solver.countPasswords(19) << endl;
    cout<< "20 : " << solver.countPasswords(20) << endl;
    cout<< solver.countPasswords(21) << endl;
    cout<< solver.countPasswords(22) << endl;
    cout<< solver.countPasswords(23) << endl;
    cout<< solver.countPasswords(24) << endl;
    cout<< solver.countPasswords(25) << endl;
    cout<< solver.countPasswords(26) << endl;
    cout<< solver.countPasswords(27) << endl;
    cout<< solver.countPasswords(28) << endl;
    cout<< solver.countPasswords(29) << endl;
    cout<< solver.countPasswords(30) << endl;
    return 0;
}
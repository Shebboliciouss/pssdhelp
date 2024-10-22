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

        map<pair<int, int>, long long> data;
        long long total_comb_pass = 0;
        for (int i = 0; i < 10; i++){

            // calc {2, 0}, {2,1}, {2,2}, {2,3} .....{2,9} if N = 2
            total_comb_pass += checkNeighbors(N, i, keypad, data);
        }

        return total_comb_pass;

    }

    long long checkNeighbors(int i, int j, map<int, vector<int>>& keypad, map<pair<int, int>, long long>& data){
    // only one cmobination of password
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
    // Example it will be a table which stores the combination of passwords in that length for each digit in the keypad 
    // with index i(number of length of the password) and  j (numbers on the keypad)
    // Memoization 
    data[{i, j}] = count;
    return count;
    
    }
};


int main() {
    UnsealTheSafe solver;

    for (auto i = 2; i < 31; i++){
        cout<< i << " : " << solver.countPasswords(i) << endl;
    }
    // cout<< "2 : " << solver.countPasswords(2) << endl;
    // cout<< "3 : " << solver.countPasswords(3) << endl;
    // cout<< "4 : " << solver.countPasswords(4) << endl;
    // cout<< "5 : " << solver.countPasswords(5) << endl;
    // cout<< "6 : " << solver.countPasswords(6) << endl;
    // cout<< "7 : " << solver.countPasswords(7) << endl;
    // cout<< "8 : " << solver.countPasswords(8) << endl;
    // cout<< "9 : " << solver.countPasswords(9) << endl;
    // cout<< "10 : " << solver.countPasswords(10) << endl;
    // cout<< "11 : " << solver.countPasswords(11) << endl;
    // cout<< "12 : " <<solver.countPasswords(12) << endl;
    // cout<< "13 : " << solver.countPasswords(13) << endl;
    // cout<< "14 : " << solver.countPasswords(14) << endl;
    // cout<< "15 : " << solver.countPasswords(15) << endl;
    // cout<< "16 : " << solver.countPasswords(16) << endl;
    // cout<< "17 : " << solver.countPasswords(17) << endl;
    // cout<< "18 : " << solver.countPasswords(18) << endl;
    // cout<< "19 : " << solver.countPasswords(19) << endl;
    // cout<< "20 : " << solver.countPasswords(20) << endl;
    // cout<< solver.countPasswords(21) << endl;
    // cout<< solver.countPasswords(22) << endl;
    // cout<< solver.countPasswords(23) << endl;
    // cout<< solver.countPasswords(24) << endl;
    // cout<< solver.countPasswords(25) << endl;
    // cout<< solver.countPasswords(26) << endl;
    // cout<< solver.countPasswords(27) << endl;
    // cout<< solver.countPasswords(28) << endl;
    // cout<< solver.countPasswords(29) << endl;
    // cout<< solver.countPasswords(30) << endl;
    return 0;
}
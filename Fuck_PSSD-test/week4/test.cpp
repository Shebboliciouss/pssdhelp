#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class UnsealTheSafe{
    public:
    long countPasswords(int N){
        vector<vector<long>> dp(N+1, vector<long>(10, 0));
        //memset(dp, 0, sizeof(num));
        // int **dp = new int*[N+1];
        // for(int i = 0; i < N+1; i++){
        //     dp[i] = new int[10];
        // }

        for (int i = 0; i < 10; i++){
            dp[1][i] = 1;
        }

        for (int i = 2; i < N+1; i++){
            // Set the latest known combination for the current key press.
            // 0 can only come from 7
            dp[i][0] = dp[i-1][7];
            // 1 can come from 2 and 4.
            dp[i][1] = dp[i-1][2] + dp[i-1][4];
            // 2 can come from 1, 3 and 5.
            dp[i][2] = dp[i-1][1] + dp[i-1][3] + dp[i-1][5];
            // 3 can come from 2 and 6.
            dp[i][3] = dp[i-1][2] + dp[i-1][6];
            // 4 can come from 1, 5 and 7.
            dp[i][4] = dp[i-1][1] + dp[i-1][5] + dp[i-1][7];
            // 5 can come from 2, 4, 6 and 8.
            dp[i][5] = dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8];
            // 6 can come from 3, 5 and 9.
            dp[i][6] = dp[i-1][3] + dp[i-1][5] + dp[i-1][9];
            // 7 can come from 4, 8 and 0.
            dp[i][7] = dp[i-1][4] + dp[i-1][8] + dp[i-1][0];
            // 8 can come from 5, 7 and 9.
            dp[i][8] = dp[i-1][5] + dp[i-1][7] + dp[i-1][9];
            // 9 can come from 6 and 8.
            dp[i][9] = dp[i-1][6] + dp[i-1][8];
        }

        long long total_comb_pass = 0;
        for (int i = 0; i < 10; i++){
            total_comb_pass += dp[N][i];
        }

        // for(int i = 0; i < N+1; i++){
        //     delete[] dp[i];
        //     delete[] dp;
        // }

        return total_comb_pass;

    }
};

int main() {
    UnsealTheSafe solver;
    cout<< solver.countPasswords(25) << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class CastleGuards
{
  public:
  int missing (vector <string> castle)
  {
    int rows = castle.size (), cols = castle [0].length ();
    
    int r = 0, c = 0;
    
    for (int i = 0; i < rows; i++)
    {
      bool empty = true;
      
      for (int j = 0; j < cols; j++)
        if (castle [i][j] == 'X')
          empty = false;
      
      if (empty) r++;
    }
    
    for (int j = 0; j < cols; j++)
    {
      bool empty = true;
      
      for (int i = 0; i < rows; i++)
        if (castle [i][j] == 'X')
          empty = false;
      
      if (empty) c++;
    }
    
    return max (r, c);
  }
};

 
class CastleGuard {
public:
    vector<long long> walk(int N, int R, vector <int> commands) {
        vector<long long> p(N, 0);
        long long sum = 0;
        for (int pos = 0, i = 0; i < commands.size(); ++i) {
            int round = abs(commands[i]) / N;
            for (int j = 0; j < N; ++j) {
                p[j] += round;
            }
            int oldPos = pos;
            pos = (int)update(commands[i], pos, N);
            for (int j = 0; j < abs(commands[i]) % N; ++j) {
                int jj = (oldPos + (commands[i] > 0 ? j + 1: -j - 1)) % N;
                if (jj < 0) jj += N;
                ++p[jj];
            }
            sum = update(commands[i], sum, N);
        }
//        cout << "sum: " << sum << endl;
//        printVec(p);
        vector<long long> ans(N, 0);
        for (int i = 0, pos = 0; i < R; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[(j + pos) % N] += p[j];
            }
            pos = (sum + pos) % N;
//            cout << "pos: " << pos << endl;
            
            if (pos == 0) {
                int cnt = i + 1;
                int left = (R - cnt) / cnt;
                for (int j = 0; j < N; ++j) {
                    ans[j] *= (left + 1);
                }
                i += left * cnt;
            }
        }
        ans[0]++;
        
        return ans;
    }
    
    void printVec(vector<long long> vec) {
        for (auto v: vec) {
            cout << v << ' ';
        }
        cout << endl;
    }
    void test() {
    
//        printVec(walk(10,
//                      3,
//                      {1}));
//        printVec(walk(10,
//                      1234,
//                      {2, -3, 1}));
//        printVec(walk(97,
//                      1000,
//                      {314}));
//        printVec(walk(47,
//                      123,
//                      {1, -2, 3, -4, 5, -6, 7, -8, 9, -10}));
        
printVec(walk(3,
              9,
              {-1000000000}));
        
    }
private:
    long long update(long long update, long long current, long long num) {
        current += update;
        current %= num;
        if (current < 0) {
            current += num;
        }
        return current;
    }
};
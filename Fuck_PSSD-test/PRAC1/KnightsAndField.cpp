// #include <vector>
// #include <string>
// #include <iostream>
// class KnightsAndField {
// public:
//     static int place(std::vector<std::string>& field) {
//         int numRows = field.size();
//         int numCols = field[0].size();
//         int knightsNeeded = 0;

//         // Create arrays to keep track of unvisited rows and columns
//         std::vector<bool> unvisitedRows(numRows, true);
//         std::vector<bool> unvisitedCols(numCols, true);

//         // Count the number of unvisited rows and columns
//         for (int i = 0; i < numRows; ++i) {
//             for (int j = 0; j < numCols; ++j) {
//                 if (field[i][j] == 'X') {
//                     unvisitedRows[i] = false;
//                     unvisitedCols[j] = false;
//                 }
//             }
//         }

//         // Count the number of additional knights needed
//         for (int i = 0; i < numRows; ++i) {
//             if (unvisitedRows[i]) {
//                 knightsNeeded++;
//             }
//         }

//         for (int j = 0; j < numCols; ++j) {
//             if (unvisitedCols[j]) {
//                 knightsNeeded++;
//             }
//         }

//         return knightsNeeded;
//     }
// };

// // Include the required headers
// #include <iostream>
// #include <vector>
// #include <string>

// // Declare the namespace
// using namespace std;

// // Declare the class
// class KnightAndField 
// {
// public:

//     // public method
//     int place(vector<string> &f) 
//     {
//         // Assign the values
//         int r = f.size();
//         int c = f[0].size();
//         int additional_row_knights = 0;
//         int additional_col_knights = 0;

//         // Check each row
//         for (int g = 0; g < r; g++) 
//         {
//             // Assign the value
//             bool has_knight = false;
            
//             // for loop
//             for (int h = 0; h < c; h++) 
//             {
//                 // Check teh condition
//                 if (f[g][h] == 'X') 
//                 {
//                     // Assign the value
//                     has_knight = true;
                    
//                     // Break statement 
//                     break;
//                 }
//             }
            
//             // Check the condition
//             if (!has_knight) 
//             {
//                 // Incremenet the value
//                 int additional_row_knights = 0;
//             }
//         }

//         // Check each column
//         for (int h = 0; h < c; h++)
//         {
//             // Assign the value
//             bool has_knight = false;
            
//             // for loop
//             for (int g = 0; g < r; g++) 
//             {
//                 // Check teh condition
//                 if (f[g][h] == 'X') 
//                 {
//                     // Assign the value
//                     has_knight = true;
//                     break;
//                 }
//             }
            
//             // Check the condition
//             if (!has_knight) 
//             {
//                 // Incremenet the value
//                 additional_col_knights++;
//             }
//         }

//         int additional_knights = additional_col_knights;
//         return additional_knights;
//     }
// };

// Include the required headers
#include <iostream>
#include <vector>
#include <string>

// Declare the namespace
using namespace std;

// Declare the class
class KnightAndField 
{
public:

    // public method
    int place(vector<string> &f) 
    {
        // Assign the values
        int r = f.size();
        int c = f[0].size();
        int additional_row_knights = 0;
        int additional_col_knights = 0;

        // Check each row
        for (int g = 0; g < r; g++) 
        {
            // Assign the value
            bool has_knight = false;
            
            // for loop
            for (int h = 0; h < c; h++) 
            {
                // Check the condition
                if (f[g][h] == 'X') 
                {
                    // Assign the value
                    has_knight = true;
                    
                    // Break statement 
                    break;
                }
            }
            
            // Check the condition
            if (!has_knight) 
            {
                // Increment the value
                additional_row_knights++;
            }
        }

        // Check each column
        for (int h = 0; h < c; h++)
        {
            // Assign the value
            bool has_knight = false;
            
            // for loop
            for (int g = 0; g < r; g++) 
            {
                // Check the condition
                if (f[g][h] == 'X') 
                {
                    // Assign the value
                    has_knight = true;
                    break;
                }
            }
            
            // Check the condition
            if (!has_knight) 
            {
                // Increment the value
                additional_col_knights++;
            }
        }

        int additional_knights = max(additional_row_knights, additional_col_knights);
        return additional_knights;
    }
};


// Main method
int main() 
{
    // Create an instance
    KnightAndField s;
    
    // Declare a vector
    vector<string> f2 = {
        "....",
        "....",
        "....",
        "...."
    };
    
    // Invoke the function
    int a = s.place(f2);
    
    // Display the result
    cout << "Additional Knights Needed: " << abs(a) << endl;
    
    // Declare a vector
    vector<string> f3 = {
        "XX...",
        ".XX..",
        "...XX"
    };
   
    // Invoke the function
    int c = s.place(f3);
    
    // Display the result
    cout << "Additional Knights Needed: " << c << endl;
    
    // Declare a vector
    vector<string> f4 = 
    {
        "........X..",
        "...X.......",
        "...........",
        "..X...X....",
        "...........",
        "...........",
        "........X..",
        "...........",
        "...........",
        "........X..",
        ".....X....."
    };
   
    // Invoke the function
    int d = s.place(f4);
    
    // Display the result
    cout << "Additional Knights Needed: " << d << endl;

    // Declare a vector
    vector<string> f5 = 
    {
        "....XXXX", 
        "........", 
        "XX.X.XX.", 
        "........", 
        "........" 
    };
   
    // Invoke the function
    int e = s.place(f5);
    
    // Display the result
    cout << "Additional Knights Needed: " << e << endl;
    return 0;
}

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

class CastleGuards{
public:
	int missing(vector<string> castle){
		int emptyRows = 0;
		int emptyCols = 0;
		int rowsInventory[50] = {0};
		int colsInventory[50] = {0};
		for(int i = 0; i<castle.size(); ++i){
			for (int j = 0; j<castle[i].length(); ++j){
				if (castle[i][j] == 'X'){
					rowsInventory[i] = 1;
					colsInventory[j] = 1;
				}
			}
			if(rowsInventory[i] == 0){
				emptyRows++;
			}
		}
		for(int k = 0; k < castle[0].length(); ++k){
			if(colsInventory[k] == 0){
				emptyCols++;
			}
		}
		return max(emptyCols, emptyRows);
	}
};

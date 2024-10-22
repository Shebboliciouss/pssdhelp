#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;                                    //      0  1  2  3  4
                                                       //   0 | 4  2  1  0  1      
class SquareOfDigits{                                  //   1 | 2  2  1  0  0     
public:                                                //   2 | 2  2  1  0  1                             
    int getMax(vector<string> data){                                                                            
        int row = data.size();   //3                                                        
        int column = data[0].size();   //5                                  
        int square = 1;
        // Iterate through each cell in the grid as the top-left corner of a potential square
        for (int i = 0; i < row; i++){                             // i==   0      1     2
            for(int j = 0; j < row - i; j++){                     // j==   012    01    0
                for (int k = 0; k < column - i; k++){             // k==   01234  0123  012
                    // checking the corners of the cell whether its the same digit
                    if ((data[j].at(k) == data[j].at(k+i)) && (data[j].at(k) == data[j+i].at(k)) && (data[j].at(k) == data[j+i].at(k+i))){
                        // If all corners have same digit, update the maximum square size
                        square = max(square, ((i+1)*(i+1)));
                    }
                }
            }
        }
        return square; // Return the maximum square size found
    }
};

int main() {
    SquareOfDigits squareOfDigits;

    // Test cases
    vector<string> grid1 = {"12", "34"};
    cout << "Test case 1: " << squareOfDigits.getMax(grid1) << endl; //1

    vector<string> grid2 = {"1255", "3455"};
    cout << "Test case 2: " << squareOfDigits.getMax(grid2) << endl; //4

    vector<string> grid3 = {"42101", "22100", "22101"};
    cout << "Test case 3: " << squareOfDigits.getMax(grid3) << endl; //9

    vector<string> grid4 = {"1234567890"};
    cout << "Test case 4: " << squareOfDigits.getMax(grid4) << endl; //1

    vector<string> grid5 = {
        "9785409507",
        "2055103694",
        "0861396761",
        "3073207669",
        "1233049493",
        "2300248968",
        "9769239548",
        "7984130001",
        "1670020095",
        "8894239889",
        "4053971072"
    };
    cout << "Test case 5: " << squareOfDigits.getMax(grid5) << endl; //49

    return 0;
}

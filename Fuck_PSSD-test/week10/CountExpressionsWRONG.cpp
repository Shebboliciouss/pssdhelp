#include <string>
#include <iostream>
using namespace std;

class CountExpressions {
public:
    int calcExpressions(int x, int y, int val) {
        int ops[3] = { -1, 0, 1 }; // -1 for '-', 0 for '+', 1 for '*'
        int count = 0;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (calculate(x, x, y, y, ops[i], ops[j], ops[k]) == val) ++count;
                    if (calculate(x, y, x, y, ops[i], ops[j], ops[k]) == val) ++count;
                    if (calculate(x, y, y, x, ops[i], ops[j], ops[k]) == val) ++count;
                    if (calculate(x, x, y, y, ops[i], ops[j], ops[k]) == val) ++count;
                }
            }
        }
        
        return count;
    }

private:
    int calculate(int a, int b, int c, int d, int op1, int op2, int op3) {
        return operate(operate(operate(a, b, op1), c, op2), d, op3);
    }

    int operate(int a, int b, int op) {
        if (op == -1) return a - b;
        else if (op == 0) return a + b;
        else return a * b;
    }
};

int main() {
    CountExpressions ce;
    
    // Test case 0
    cout << ce.calcExpressions(7, 8, 16) << endl; //== 9);
    
    // Test case 1
    cout << ce.calcExpressions(3, 5, 7) << endl; //== 5);
    
    // Test case 2
    cout << ce.calcExpressions(99, 100, 98010000) << endl; //== 6);
    
    // Test case 3
    cout << ce.calcExpressions(-99, 42, -1764) << endl; //== 2);

    // Test case 4
    cout << ce.calcExpressions(100, -100, -100000000) << endl; //== 0);

    // Test case 5
    cout << ce.calcExpressions(1, 2, 5) << endl; //== 17);

    // Additional test cases
    // Test case 6: Testing with equal x and y values and a positive val
    cout << ce.calcExpressions(2, 2, 4) << endl; //== 0);

    // Test case 7: Testing with equal x and y values and a negative val
    cout << ce.calcExpressions(-2, -2, -4) << endl; //== 0);

    // Test case 8: Testing with a large positive val
    cout << ce.calcExpressions(10000, -10000, 100000000) << endl; //== 0);

    return 0;
}

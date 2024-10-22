
#include <iostream>
#include <vector>
using namespace std;

class DerivativeSequence{
    public:
    vector<int> derSeq(vector<int> a, int n){
        int size = a.size();
        vector<int> result = a;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < size-1; j++){
                result[j] = result[j+1]-result[j];
            }
            result.pop_back();
        }
        return result;
    }
};

int main() {
    DerivativeSequence ds;

    // Test case 0
    vector<int> test0 = {5, 6, 3, 9, -1};
    vector<int> result0 = ds.derSeq(test0, 1);
    cout << "Test case 0: ";
    for (int num : result0) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 1
    vector<int> test1 = {5, 6, 3, 9, -1};
    vector<int> result1 = ds.derSeq(test1, 2);
    cout << "Test case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> test2 = {5, 6, 3, 9, -1};
    vector<int> result2 = ds.derSeq(test2, 4);
    cout << "Test case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> test3 = {4, 4, 4, 4, 4, 4, 4, 4};
    vector<int> result3 = ds.derSeq(test3, 3);
    cout << "Test case 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 4
    vector<int> test4 = {-100, 100};
    vector<int> result4 = ds.derSeq(test4, 0);
    cout << "Test case 4: ";
    for (int num : result4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

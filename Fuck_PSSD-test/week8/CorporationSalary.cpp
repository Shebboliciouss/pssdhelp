#include <vector>
#include <string>
//#include <numeric>
#include <iostream>

using namespace std;

class CorporationSalary {
private:
    int length;
    vector<string> relationship;
public:
     int Salary(int index, vector<long>& pay) {
        if (pay[index] != -1) {
            return pay[index];
        }

        long total = 0;
        for (int j = 0; j < length; j++) {
            if (relationship[index][j] == 'Y') {
                total += Salary(j, pay);
            }
        }

        // If it's just "N" that means that employees is not a manager of anyone then his salary is 1.
        if (total == 0) {
            total = 1;
        }

        pay[index] = total;
        
        return total;
    }

    long totalSalary(vector<string> relations) {
        length = relations.size();
        relationship = relations;
        vector<long> pay(length, -1);
        long totalPay = 0;
        for (int i = 0; i < length; i++) {
            totalPay += Salary(i, pay);
            //Salary(i, pay);
        }
        return totalPay;
        //return accumulate(pay.begin(), pay.end(), 0);
    }

   
};


int main() {
    CorporationSalary cs;
    vector<string> relations0 = {"N"};
    cout << "Test case 0 -- Expected: 1, Actual: " << cs.totalSalary(relations0) << endl;

    vector<string> relations1 = {"NNYN", "NNYN", "NNNN", "NYYN"};
    cout << "Test case 1 -- Expected: 5, Actual: " << cs.totalSalary(relations1) << endl;

    vector<string> relations2 = {"NNNNNN", "YNYNNY", "YNNNNY", "NNNNNN", "YNYNNN", "YNNYNN"};
    cout << "Test case 2 -- Expected: 17, Actual: " << cs.totalSalary(relations2) << endl;

    vector<string> relations3 = {"NYNNYN", "NNNNNN", "NNNNNN", "NNYNNN", "NNNNNN", "NNNYYN"};
    cout << "Test case 3 -- Expected: 8, Actual: " << cs.totalSalary(relations3) << endl;

    vector<string> relations4 = {"NNNN", "NNNN", "NNNN", "NNNN"};
    cout << "Test case 4 -- Expected: 4, Actual: " << cs.totalSalary(relations4) << endl;

    return 0;
}

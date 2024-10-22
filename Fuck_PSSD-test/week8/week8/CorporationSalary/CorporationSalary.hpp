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
        // return the computed value for that employee's salary
        if (pay[index] != -1) {
            return pay[index];
        }

        long total = 0;
        for (int j = 0; j < length; j++) {
            // if it encounters a "Y" that means employee[index] is a manager of employee[j]
            if (relationship[index][j] == 'Y') {
                // so we have to accumulate the wages of its subordinates
                total += Salary(j, pay);
            }
        }

        // If it's just "N" that means that employees is not a manager of anyone then his salary is 1.
        if (total == 0) {
            total = 1;
        }

        // update the vector with the computed salaries
        pay[index] = total;
        
        return total;
    }

    long totalSalary(vector<string> relations) {
        length = relations.size();
        relationship = relations;

        // initialise all the employees salary as -1
        vector<long> pay(length, -1);
        long totalPay = 0;

        // calculate each employees salary
        for (int i = 0; i < length; i++) {
            totalPay += Salary(i, pay);
            //Salary(i, pay);
        }
        return totalPay;
        //return accumulate(pay.begin(), pay.end(), 0);
    }

   
};
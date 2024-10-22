#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class DownloadingFiles{
    public: 
        double actualTime(vector<string> tasks){
            double bandwidth = 0.0;
            //double time = 0.0;
            double remainingTime = 0.0;
            vector<pair<int, int>> speedTime;
            int n = tasks.size();
            for (int i = 0; i < n; i ++){
                int pos = tasks[i].find(" ");
                speedTime.push_back(make_pair(stoi(tasks[i].substr(pos+1)),stoi(tasks[i].substr(0,pos))));
            }
            
            //sort(speedTime.begin(), speedTime.end());

            // time += speedTime[0].first;

            // for (int i = 0; i < n; i++){
            //     bandwidth+=speedTime[i].second;            
            // }

            // for(int i = 1; i < n; i++){
            //     speedTime[i].first = speedTime[i].first - time;
            //     remainingTime += speedTime[i].second * speedTime[i].first/bandwidth;
            // }

            // time += remainingTime;

            // return (long double)time;

            for (int i = 0; i < n; i++){
               bandwidth += speedTime[i].second;
               remainingTime += speedTime[i].second*speedTime[i].first;
            }
            return (long double)remainingTime/(long double)bandwidth;

        }
};

int main() {
    DownloadingFiles df;
    
    vector<string> test1 = {"3 57", "2 22"};
    cout << "Test Case 1 - Remaining time: " << df.actualTime(test1) << " seconds" << endl;
    
    vector<string> test2 = {"3 1057", "2 1022"};
    cout << "Test Case 2 - Remaining time: " << df.actualTime(test2) << " seconds" << endl;
    
    vector<string> test3 = {"25 1000", "5 5000", "10 5000"};
    cout << "Test Case 3 - Remaining time: " << df.actualTime(test3) << " seconds" << endl;
    
    vector<string> test4 = {"1 10", "1 20", "2 40"};
    cout << "Test Case 4 - Remaining time: " << df.actualTime(test4) << " seconds" << endl;
    
    vector<string> test5 = {"6 88", "39 7057", "63 2502", "45 2285", "28 8749", "62 3636", "1 5546", "49 5741"};
    cout << "Test Case 5 - Remaining time: " << df.actualTime(test5) << " seconds" << endl;

    return 0;
}

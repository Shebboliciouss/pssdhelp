#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class AzimuthMonitoring {
//  public:
//   int getAzimuth(vector<string> a) {
//     int degree = 0;

//     for (int i = 0; i < a.size(); i++) {
//         // HALT
//       if (a[i][0] == 'H')
//         break;
//         // TURN AROUND
//       else if (a[i][0] == 'T')
//         degree += 180;
        
//         // 4 --> LEFT, 5 --> RIGHT
//       else if (a[i].size() == 4 || a[i].size() == 5) {
//         if (a[i][0] == 'L')
//           degree -= 90;
//         else
//           degree += 90;
//       }

//       else {
//         istringstream in(a[i]);

//         string s;
//         int c;
//         in >> s >> c;
//         if (s[0] == 'L')
//           degree -= c;
//         else
//           degree += c;
//       }
//     }
//     while (degree < 0) degree += 360;
//     return degree % 360;
//   }
// };

class AzimuthMonitoring {
 public:
  int getAzimuth(vector<string> instructions) {
    int n = instructions.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (instructions[i] == "HALT") {
        break;
      } else if (instructions[i] == "TURN AROUND") {
        sum += 180;
      } else if (instructions[i] == "LEFT") {
        sum += -90;
      } else if (instructions[i] == "RIGHT") {
        sum += 90;
      } else {
        int pos = instructions[i].find(" ");
        string direction = instructions[i].substr(0, pos);
        string number = instructions[i].substr(pos + 1);
        int num = stoi(number);
        if (direction == "LEFT") {
          sum -= num;
        } else if (direction == "RIGHT") {
          sum += num;
        }
      }
    }
    //-450-->270

    if (sum == 360) {
      sum = 0;
    } else if (sum >= 360){
      sum = sum % 360;
    } else if (sum < 0) {
      int sum1 = sum % 360;
      sum = 360 + sum1;
    } 

    // if (sum > 360){
    //     sum = sum%360;
    // }
    // if (sum < 0){
    //     sum = sum%360;
    //     sum = 360 - sum;
    // }
    return sum;
  }
};

int main() {
  AzimuthMonitoring azimuthMonitor;

  vector<string> instructions1 = {"RIGHT"};
  cout << "Final Azimuth for instructions1: "
       << azimuthMonitor.getAzimuth(instructions1) << endl;  // 90

  vector<string> instructions2 = {"LEFT", "LEFT", "LEFT", "LEFT", "HALT", "LEFT", "LEFT"};
  cout << "Final Azimuth for instructions2: "
       << azimuthMonitor.getAzimuth(instructions2) << endl;  // 0

//   vector<string> instructions3 = {"LEFT 5",  "RIGHT 10", "LEFT 15", "RIGHT 20",
//                                   "LEFT 25", "RIGHT 30", "LEFT 35", "RIGHT 40"};
//   cout << "Final Azimuth for instructions3: "
//        << azimuthMonitor.getAzimuth(instructions3) << endl;  // 20

//   vector<string> instructions4 = {"RIGHT 59", "RIGHT", "RIGHT", "HALT",
//                                   "LEFT",     "LEFT",  "LEFT"};
//   cout << "Final Azimuth for instructions4: "
//        << azimuthMonitor.getAzimuth(instructions4) << endl;  // 239

//   vector<string> instructions5 = {"TURN AROUND", "HALT",   "LEFT 5",
//                                   "HALT",        "LEFT 5", "HALT"};
//   cout << "Final Azimuth for instructions5: "
//        << azimuthMonitor.getAzimuth(instructions5) << endl;  // 180

//   vector<string> instructions6 = {"LEFT", "LEFT", "LEFT",
//                                   "LEFT", "LEFT", "HALT"};
//   cout << "Final Azimuth for instructions6: "
//        << azimuthMonitor.getAzimuth(instructions6) << endl;  // 270

//   vector<string> instructions7 = {
//       "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT",
//       "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT",
//       "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT",
//       "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT",
//       "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT",
//       "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT", "RIGHT",
//       "RIGHT", "RIGHT"};
//   cout << "Final Azimuth for instructions7: "
//        << azimuthMonitor.getAzimuth(instructions7) << endl;  // 180

//   vector<string> instructions8 = {"LEFT"};
//   cout << "Expected: 270, Actual: " << azimuthMonitor.getAzimuth(instructions8)
//        << endl;

//   vector<string> instructions9 = {"TURN AROUND"};
//   cout << "Expected: 180, Actual: " << azimuthMonitor.getAzimuth(instructions9)
//        << endl;

//   vector<string> instructions10 = {"LEFT 1"};
//   cout << "Expected: 359, Actual: " << azimuthMonitor.getAzimuth(instructions10)
//        << endl;

//   vector<string> instructions11 = {"LEFT 179"};
//   cout << "Expected: 181, Actual: " << azimuthMonitor.getAzimuth(instructions11)
//        << endl;

//   vector<string> instructions12 = {"RIGHT 1"};
//   cout << "Expected: 1, Actual: " << azimuthMonitor.getAzimuth(instructions12)
//        << endl;

//   vector<string> instructions13 = {"RIGHT 179"};
//   cout << "Expected: 179, Actual: " << azimuthMonitor.getAzimuth(instructions13)
//        << endl;

//   vector<string> instructions14 = {"HALT"};
//   cout << "Expected: 0, Actual: " << azimuthMonitor.getAzimuth(instructions14)
//        << endl;

//   vector<string> instructions15 = {"LEFT 58", "RIGHT 57"};
//   cout << "Expected: 359, Actual: " << azimuthMonitor.getAzimuth(instructions15)
//        << endl;

  return 0;
}

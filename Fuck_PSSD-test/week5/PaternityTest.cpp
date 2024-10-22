#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class PaternityTest {
 public:
  vector<int> possibleFathers(string child, string mother, vector<string> men) {
    vector<int> result;
    int dad = men.size();
    int children = child.size();
    int end;
    for (int i = 0; i < dad; i++) {
      int similar = 0;
      for (int j = 0; j < children; j++) {
        if (child[j] == men[i][j]) {
          similar++;
        } else {
          if (child[j] != mother[j]) {
            break;
          }
        }
        end = j;
      }

      int half = child.size() / 2;
      if (similar >= half && end+1 == children) {
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  // Test cases
  PaternityTest p;
  vector<int> result1 = p.possibleFathers("ABCD", "AXCY", {"SBTD", "QRCD"});
  vector<int> result2 =
      p.possibleFathers("ABCD", "ABCX", {"ABCY", "ASTD", "QBCD"});
  vector<int> result3 = p.possibleFathers(
      "ABABAB", "ABABAB", {"ABABAB", "ABABCC", "ABCCDD", "CCDDEE"});
  vector<int> result4 = p.possibleFathers(
      "YZGLSYQT", "YUQRWYQT",
      {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"});
  vector<int> result5 = p.possibleFathers(
      "WXETPYCHUWSQEMKKYNVP", "AXQTUQVAUOSQEEKCYNVP",
      {"WNELPYCHXWXPCMNKDDXD", "WFEEPYCHFWDNPMKKALIW", "WSEFPYCHEWEFGMPKIQCK",
       "WAEXPYCHAWEQXMSKYARN", "WKEXPYCHYWLLFMGKKFBB"});

  // Print the results
  cout << "Result 1: { ";
  for (int i : result1) {
    cout << i << " ";
  }
  cout << "}" << endl;

  cout << "Result 2: { ";
  for (int i : result2) {
    cout << i << " ";
  }
  cout << "}" << endl;

  cout << "Result 3: { ";
  for (int i : result3) {
    cout << i << " ";
  }
  cout << "}" << endl;

  cout << "Result 4: { ";
  for (int i : result4) {
    cout << i << " ";
  }
  cout << "}" << endl;


  cout << "Result 5: { ";
  for (int i : result5) {
    cout << i << " ";
  }
  cout << "}" << endl;


  return 0;
}

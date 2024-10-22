#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unordered_set>

using namespace std;
class NiceOrUgly {
 public:
  // find the length of a prefix of 'str' that contains only characters present
  // in the 'finds' array. It returns the length of this prefix. int
  // count(string str, string search) {
  //   int n = str.size();
  //   int length = search.size();
  //   // keep track of whether a character in str is found in finds
  //   for (int i = 0; i < n; i++) {
  //     bool found = false;
  //     for (int j = 0; j < length; j++) {
  //       if (str[i] == search[j]) {
  //         found = true;
  //         break;
  //       }
  //     }
  //     if (!found) {
  //       return i;
  //     }
  //   }
  //   return n;
  // }

  // int consecutive(string str, string search) {
  //   int n = str.size();

  //   // Create an unordered set to store characters from the 'search' string
  //   std::unordered_set<char> searchSet(search.begin(), search.end());

  //   int prefixLength = 0;
  //   while (prefixLength < n && searchSet.find(str[prefixLength]) != searchSet.end()) {
  //     prefixLength++;
  //   }

  //   return prefixLength;
  // }

  int consecutive(string str, string search) {
    int n = str.size();
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (search.find(str[i]) != std::string::npos) {
            count++;
        } else {
            count = 0;
        }

        maxCount = std::max(maxCount, count);
    }

    return maxCount;
  }

  bool checkVowel(char character) {
    // return true if the statement is met
    return (character == 'A' || character == 'E' || character == 'I' ||
            character == 'O' || character == 'U');
  }

  string describe(string s) {
    bool nice = true;
    bool ugly = false;
    int vowel = 0;
    int consonant = 0;
    int result = 0;
    int n = s.size();

    // check whether it could be NOT NICE
    for (int i = 0; i < n; i++) {
      if (checkVowel(s[i])) {
        // if its a vowel increment the vowel and reset the consonant counter
        consonant = 0;
        vowel++;
        // if vowel counter reaches to 3, then it is NOT NICE
        if (vowel == 3) {
          nice = false;
        }
      } else if (s[i] == '?') {
        // checks whether if theres already 2 vowels before it
        if (vowel == 2) {
          // the '?' cannot be a vowel if not it would be UGLY so reset vowel counter and increment the consonant counter
          vowel = 0;
          consonant++;
        // checks whether if theres already 4 consonant before it
        } else if (consonant == 4) {
          // the '?' cannot be another consonant if not it would be UGLY so reset consonant counter and increment the vowel counter
          consonant = 0;
          vowel++;
        } else {
          // it could be either vowel or consonant and it wouldn't turn UGLY, so reset both counters as it could be either.
          vowel = 0;
          consonant = 0;
        }
      } else {
        // if not vowel or '?' then it would a be consonant, so incremenent consonant and reset vowel
        consonant++;
        vowel = 0;

        // if  consonant counter reaches to 5, then it is NOT NICE
        if (consonant == 5) {
          nice = false;
        }
      }

      
      // Check "UGLY" conditions within the loop
      result = consecutive(s.substr(i), "?AEIOU");
      if (result >= 3) {
        ugly = true;
      }

      result = consecutive(s.substr(i), "?BCDFGHJKLMNPQRSTVWXYZ");
      if (result >= 5) {
        ugly = true;
      }

      // // If it's not nice, return "UGLY"
      // if (!nice) {
      //   return "UGLY";
      // }
    
    }

    
    // for (int i = 0; i < n; i++) {
    //   result = consecutive(s.substr(i), "AEIOU");
    //   if (result >= 3) {
    //     return "UGLY";
    //   }
    //   result = consecutive(s.substr(i), "AEIOU?");
    //   if (result >= 3) {
    //     ugly = true;
    //   }

    //   result = consecutive(s.substr(i), "BCDFGHJKLMNPQRSTVWXYZ");
    //   if (result >= 5) {
    //     return "UGLY";
    //   }

    //   result = consecutive(s.substr(i), "BCDFGHJKLMNPQRSTVWXYZ?");
    //   if (result >= 5) {
    //     ugly = true;
    //   }
    // }

    
    
    //int result = 0;
    // check whether it could be UGLY
    // result = consecutive(s, "AEIOU");
    // if (result >= 3) {
    //     return "UGLY";
    // }

    // result = consecutive(s, "?AEIOU");
    // if (result >= 3) {
    //     ugly = true;
    // }

    // result = consecutive(s, "BCDFGHJKLMNPQRSTVWXYZ");
    // if (result >= 5) {
    //     return "UGLY";
    // }

    // result = consecutive(s, "?BCDFGHJKLMNPQRSTVWXYZ");
    // if (result >= 5) {
    //     ugly = true;
    // }

    if (ugly) {
      if (nice) {
        // if it could be either ugly or nice
        return "42";
      } else {
        return "UGLY";
      }
    }else{
      return "NICE";
    }
  }
};

int main() {
  NiceOrUgly c;
  cout << c.describe("HELLOWORLD") << endl;                  // NICE
  cout << c.describe("ABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl;  // UGLY
  cout << c.describe("HELLOW?RLD") << endl;                  // 42
  cout << c.describe("H??LOWOR??") << endl;                  // NICE
  cout << c.describe("EE?FFFF") << endl;                     // UGLY
  cout << c.describe("?") << endl;                           // NICE
  cout << c.describe("??") << endl;                          // NICE
  cout << c.describe("???") << endl;                         // 42
  cout << c.describe("????") << endl;                        // 42
  cout << c.describe("?????") << endl;                       // 42
  cout << c.describe("??????") << endl;                      // 42
  cout << c.describe("IE?LPS?E?QCL?I?VRV?A?MPD?I?BHR?O?SFJ?E?MFG?I?CHYW")
       << endl;  // UGLY
  cout << c.describe("EI?RQQ?A?WWQ?I?QRQ?A?QRQ?I?WQR?A?RWR?E?WQR?E?QRR")
       << endl;  // 42
  cout << c.describe("O?ZPB?I?FXR?I?QCL?E?NHJ?O?MQM?O?MWX?E?CYY?A?GCGL")
       << endl;  // 42
  cout << c.describe("AA?QQQ?A?QQQ?A?QQQ?A??QQQ?A?QQQ?A?QQQ?A?QQQ?A?QQQQ")
       << endl;  // 42
  cout << c.describe("IU?QQQ?E?QQQ?O?QQQ?AI??QQQ?U?QQQ?O?QQQ?I?QQQQ")
       << endl;  // UGLY
  cout << c.describe("AA?ZPC?A?LSQ?A?RQG?A??YHQT??A?CCL?A?HLG?A?FFTW")
       << endl;  // 42
  cout << c.describe("OQUQIQIQEQAQOQEQAQUQIQIQUQIQEQAQAQIQOQAQAQUQIQOQOQ")
       << endl;  // NICE
}
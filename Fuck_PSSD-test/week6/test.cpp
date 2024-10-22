#include <iostream>
using namespace std;

class NiceOrUgly {
public:
    string describe(string s) {
        int consecutiveVowels = 0;
        int consecutiveConsonants = 0;

        for (char c : s) {
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                consecutiveVowels++;
                consecutiveConsonants = 0;
            } else if (c != '?') {
                consecutiveConsonants++;
                consecutiveVowels = 0;
            }

            // Check if the string is definitely "UGLY."
            if (consecutiveVowels == 3 || consecutiveConsonants == 5) {
                return "UGLY";
            }
        }

        // Check if the string is definitely "UGLY" based on consecutive characters.
        if (consecutiveVowels == 3 || consecutiveConsonants == 5) {
            return "UGLY";
        }

        // If no definite "UGLY" condition is met, check for question marks.
        for (char c : s) {
            if (c == '?') {
                // Try replacing '?' with a vowel.
                int tempVowels = consecutiveVowels + 1;
                int tempConsonants = 0;

                if (tempVowels == 3) {
                    return "UGLY"; // Replacing '?' results in "UGLY."
                }

                // Try replacing '?' with a consonant.
                tempVowels = 0;
                tempConsonants = consecutiveConsonants + 1;

                if (tempConsonants == 5) {
                    return "UGLY"; // Replacing '?' results in "UGLY."
                }
            }
        }

        // If no "UGLY" conditions are met, return "NICE."
        return "NICE";
    }
};



int main() {
    NiceOrUgly c;
    cout << c.describe("HELLOWORLD") << endl; // Output: "NICE"
    cout << c.describe("ABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl; // Output: "UGLY"
    cout << c.describe("HELLOW?RLD") << endl; // Output: "42"
    cout << c.describe("H??LOWOR??") << endl; // Output: "NICE"
    cout << c.describe("EE?FFFF") << endl; // Output: "UGLY"
    
    cout << c.describe("?") << endl;                                            //NICE 
    cout << c.describe("??") << endl;                                           //NICE       
    cout << c.describe("???") << endl;                                          //42             
    cout << c.describe("????") << endl;                                         //42           
    cout << c.describe("?????") << endl;                                        //42 
    cout << c.describe("??????") << endl;                                       //42                           
    cout << c.describe("IE?LPS?E?QCL?I?VRV?A?MPD?I?BHR?O?SFJ?E?MFG?I?CHYW") << endl;   //UGLY                                                                                                                                   
    cout << c.describe("EI?RQQ?A?WWQ?I?QRQ?A?QRQ?I?WQR?A?RWR?E?WQR?E?QRR") << endl;    //42                                   
    cout << c.describe("O?ZPB?I?FXR?I?QCL?E?NHJ?O?MQM?O?MWX?E?CYY?A?GCGL") << endl;    //42                             
    cout << c.describe("AA?QQQ?A?QQQ?A?QQQ?A??QQQ?A?QQQ?A?QQQ?A?QQQ?A?QQQQ") << endl;  //42                                 
    cout << c.describe("IU?QQQ?E?QQQ?O?QQQ?AI??QQQ?U?QQQ?O?QQQ?I?QQQQ") << endl;      //UGLY                          
    cout << c.describe("AA?ZPC?A?LSQ?A?RQG?A??YHQT??A?CCL?A?HLG?A?FFTW") << endl;     //42                         
    cout << c.describe("OQUQIQIQEQAQOQEQAQUQIQIQUQIQEQAQAQIQOQAQAQUQIQOQOQ") << endl;   //NICE          
    return 0;
}

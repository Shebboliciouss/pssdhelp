#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class PrefixFreeSets
{
public:
// string commonPrefixUtil(string& str1, string& str2)
// {
//     string result = "";
//     int len = min(str1.length(), str2.length());
 
//     // Compare str1 and str2
//     for (int i = 0; i < len; i++)
//     {
//         if (str1[i] != str2[i])
//             break;
//         result += str1[i];
//     }
 
//     return (result);
// }
 
// // A Function that returns the longest common prefix
// // from the array of strings
// string commonPrefix (vector<string> arr, int n)
// {
//     string prefix =  arr[0];
 
//     for (int i=1; i < n; i++)
//         prefix = commonPrefixUtil(prefix, arr[i]);
 
//     return (prefix);
// }



//     void maxElements(vector<string> words){
//         int n = words.size();
//         string ans = commonPrefix(words, n);
//         int length = ans.size();
//         cout << ans << endl;




        // for (int i = 0; i < length; i++){
        //     if ()
        // }
    //     // int n = words.size();
    //     // if (n <= 1){
    //     //     cout << "1" << endl;
    //     // }
    //     // sort(words.begin(), words.end());
    //     // //unique(words.begin(), words.end());
    //     // // for(int i = n-1; i >= 0; i--){
    //     // //     for (int len = 1; len <= words[i].size(); len++)
    //     // //         cout << words[i].substr(0, len) << endl;
    //     // // }
        
        




    // unordered_set<string> subset;
    // for (string word : words) {
    //     bool isPrefix = false;
    //     for (string sub : subset) {
    //         if (word.find(sub) == 0) {
    //             isPrefix = true;
    //             break;
    //         }
    //     }
    //     if (!isPrefix) {
    //         subset.insert(word);
    //     }
    // }
    // for(string word:subset){
    //     cout << word << endl;
    // }
    // cout << subset.size() << endl;




    // int results = n;
    //     for(int i = 0; i<n-1; i++){
    //         int len = words[i].size();
    //         if (words[i+1].substr(0,len) == words[i]){
    //             results--;
    //         }
    //     }

    // sort(words.begin(), words.end());
    // int count = 1;
    //     for (int i = 1; i < words.size(); i++) {

    //         if (words[i].find(words[i - 1]) != 0) {
    //             count++;
    //         }
    //     }

    //     cout <<  count << endl;
    //     int n = words.size();
    //     for(int i = 0; i < n-1; i ++){
    //         cout << words[i] << ", ";
    //     }
    //     cout << words[n-1] << endl;
    //     //cout << results << endl;
        
    int maxElements(vector<string> words){
        // get the length of the vector
        int n = words.size();
        // sort the vector of words in lexicographical order (dictionary order)
        sort(words.begin(), words.end());
        int results = 0;
        for (int i = 1; i < n; i++){
            // checking if the previous word is a prefix of the current word
            if(words[i].find(words[i-1]) != 0){
                results++;
            }
        }
        return results+1;

    }
};


int main(){
    /*
    4
    6
    1
    2

    13
    8
    12
    32
    */
    PrefixFreeSets p;
    cout << p.maxElements({"hello", "hi", "h", "run", "rerun", "running"}) << endl;
    cout << p.maxElements({"a", "b", "cba", "cbc", "cbb", "ccc"})<< endl;
    cout << p.maxElements({"a", "ab", "abc", "abcd", "abcde", "abcdef"})<< endl;
    cout << p.maxElements({"topcoder", "topcoder", "topcoding"})<< endl;
    cout << p.maxElements({"vsvvdxggvhraktqqkkfl", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsogvobw", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldp", "xgejpsemtuhshxpziqviiqs", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsogvobw", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsogvobw", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekf", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsog", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsogvobw", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldn", "eblhpwsvbgjskhfdsqmdsxxhupcydgroae", "eonijaazhtdnvwryvjdcndteoeqxncqhddqofzcus", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldp", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfsc", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfsc", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldp", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldn", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfscd", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxd", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsogvobw", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldp", "hfolqqhfvrfzdgsuuni", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdldn", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "fynrfcnxfjmqswmbwmznfzvaeocdozyorbfvcrguygztojdld", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfscd", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxd", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvb", "axcm", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvs", "anlecahk", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfscd", "eonijaazhtdnvwryvjdcndteoeqxncqhddqofzc", "eonijaazhtdnv", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxdr", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvso", "anlecahkrizwtqobdnycxeocojpumjfqtmpavuanhwvsjvbxd", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfscg", "eonijaazhtdnvcwamgwulzwwuoypkqxaxzuttvbvsot", "eonijaazhtdnvwryvjdcndteoeqxncqhddq", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibes", "hfolqqhfvrfzdgsuuniyakyrottbfgtouxbfcibesuoqekfscd", "eonijaazhtdnvpwxyeaprmzuscqdqjvs", "eonijaazhtdn", "fynrfcnxfjmqswmbwmznfzvae"})<< endl;
    cout << p.maxElements({"ojnqowuvzlvhphucujbiuupvx", "pgyqyghllhigejrhnjkaqaxscvwsvxacvobmqknkb", "ojnqowuvzlvhphucujbiuupv", "riwmyqtkybdgouvatjofohraayuinuuswtaqeevefkuqhnppmd", "riwmyqtkybdgouvatjofohraayuinuuswtaqeevefk", "pgyqyg", "pgyqygqmtdpxskhxtyjgbycltgqbuqejicvhcchwxkcl", "riwmyqtkybdgouvatjofohraayui", "riwmyqtkybdgouvatjofohraayuinuuswtaqeevefkuqhnppmd", "riwmyqtkybdgouvatjofohraayuinuuswtaqeevefkuqhnppmd", "zevyua", "pgyqyghllhigejrhnjkaqaxscvwsvxacvobmqknkbqlhqwuo", "pbxt", "gpfifnaejicobdfkqycwffllktrfujllwjqq", "pbxtuvyekqqzfjggzkjisjfbcbknidzpxrixdixhwlexpkgblv", "riwmyqtkybdgouvatjofohraayuinuuswtaqeevefkradueayf"})<< endl;
    cout << p.maxElements({"ccmukrvlwkndwhxxsfhhyustezpbwwbthyhnzkckmp", "jhrrvhkxlkojjnxilkkrlpirzklmauewkrfgyhwhifzoxwto", "o", "xht", "neiigspschfptqqnpzkdqfsburrsfhanwztgbysbxinpgeswrb", "t", "kmpvjkeldmhzgmevpqiwedazakmpxigvkkmmaoecpqfveeqrd", "mighvbjohclbfzfqnsjzzoquacdvczovy", "dfskxims", "cioc", "oyiofqhlbxzcyzuth", "mu", "eqntcmoijprskoasiezptzibulrrnfmrnibygehz"})<< endl;
    cout << p.maxElements({"jkeaqqoltlqssfpglhjgjdfuwuihuafmxi", "yinzxqercrwvymsudtzzrompqxzeulkdbnmjwspivquu", "nskapm", "yinzxqercrwvymsudtzzrompqxzeulkdbnmjwspivquuuejmbx", "ihogvogbitpjasiramjyiiimz", "leykhdxenpdwophpyjynkjjyytbkbahxdisiwfpptib", "zdbfbfosblupxqtiao", "zcguthmlaiwdeoijfkxlouqbselygtsfnlyvwsxkqlxctzm", "anndvehbegjqxbmhgzfazmyggvjoyyvrthadrmys", "suitsuinbzshsczwrgceqcppamortutbinw", "ptqchiizuciti", "hbkqvcpapfvagnwemhpczdjkrdpdwcbrgawdqemwspy", "jgxqelkmfgpjljvsdsthrxexusremiclheniitve", "leykhdxenpdwophpyjynkjjyytbkbahx", "zihhvrbyjcpprmqlbygiozfdxsaawraocukswvedurs", "ytgekfwcaskj", "suitsuinbzshsczwrgceqcppamortutbinwcuyicvwceaivb", "yinzxqercrwvymsudtzzrompqxzeulkdbnmjwspivquu", "hbkqvcpapfvagnwemhpczdjkrdpdwcbrgawdqemwspyspcb", "knsms", "pyaugqmgakwbabbsjd", "dqpwsjfmpalhyrijjqzdxsjzuyllxwptbgqjvhgtuu", "hbkqvcpapfvagnwemhpczdjkrdpdwcbrgawdqemwspyspcba", "eiegvkvxscdawtp", "hbkqvcpapfvagnwemhpczdjkrdpdwcbrgawdqem", "vyesnjhjajdiexpegiahjqwdxhhjfonsyyni", "isgpvqbzcdcbpacznbjtbiomudfnoxlnusgxgttbvedluq", "kqtflacxztrombtzalfnlqh", "suitsuinbzshsczwrgceqcppamortutbinwcuyic", "myfriynjw", "zvq", "qscbkf", "chwtidcezqulrrwbrrjywvczgbq", "bba", "rbttfdwrqycblntntuyzcuiqpz", "ptqchiizucititxfu", "yinzxqercrwvymsudtzzrompqxzeulkdbnmjwspivquu", "lvhklkiprqcvqygdabkl", "yinzxqercrwvymsudtzzrompqxzeulkdbnmjwspivquudwx", "wfeapnizvgsppotjwyelfgeoqudtduditkknxdevcso", "cvmenxcmdvbmlmxicwsailyzcghjfucry", "mwvjyogrboovclcnyrmfcaoa"})<< endl;
    return 0;

}



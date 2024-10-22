#include <iostream>
#include <stack>
#include <string>
#include <vector>

class SimpleCompressor {
public:
  SimpleCompressor(){};
  std::string uncompress(std::string data) {
    std::vector<int> counts;               // stack to store the multiples
    std::vector<std::string> segments{""}; // stack to store the substrings,
    // divided into segments

    // loop through the string
    for (char c : data) {
      if (isdigit(c)) {
        // if the current character is a number then push to counts stack
        counts.push_back(c - '0');
      } else if (c == '[') {
        // if the current character is open bracket create new segment by
        // pushing and empty string
        segments.push_back("");
      } else if (c == ']') {
        // if the current character is close bracket then get the multiple for
        // current substring
        int repeatCount = counts[counts.size() - 1];
        counts.pop_back(); // remove from stack

        // get the current substring which is a segment
        std::string segment = segments[segments.size() - 1];
        segments.pop_back();

        // multiply the amount of substring by the multiple
        for (int i = 0; i < repeatCount; ++i) {
          // add the substring to the according segment
          segments[segments.size() - 1] += segment;
        }
      } else {
        // if the current character is an alphabetical character then add to the
        // top segment.
        segments[segments.size() - 1] += c;
      }
    }

    return segments[segments.size() - 1];
  }
};

// Example
// Input: AB[2[3CD][2EF]]
// Expected: ABCDCDCDEFEFCDCDCDEFEF
//
// 1st Iteration
// counts = {};
// segments = {""};
// c = A
//
// c is a normal character so push to top segment
//
// 2nd Iteration
// counts = {};
// segments = {"A"};
// c = B
//
// c is a normal character so push to top segment
//
// 3rd Iteration
// counts = {};
// segments = {"AB"};
// c = [
//
// c is a open bracket so create new segment
//
// 4th Iteration
// counts = {};
// segments = {"AB", ""};
// c = 2
//
// c is a number so add to counts stack
//
// 5th
// counts = {2};
// segments = {"AB", ""};
// c = [
//
// c is a open bracket so create new segment
//
// 6th
// counts = {2};
// segments = {"AB","",""};
// c = 3
//
// push to counts stack
//
// 7th
// counts = {2,3};
// segments = {"AB","",""}
// c = C
//
// c is a normal character so push to top segment
//
// 8th
// counts = {2,3};
// segments{"AB","","C"};
// c = D
//
// c is a normal character so push to top segment
//
// 9th
// counts = {2,3};
// segments = {"AB","","CD"};
// c = ]
//
// c is a close bracket so get the top multiple and top segment
// counts = {2}
// multiple = 3
// segments = {"AB",""};
// segment = "CD"
//
// iterate through the range of the multiple and add the current substring of
// the segment to the top segment;
//
// counts = {2}
// segments = {"AB","CDCDCD"}
//
// 10th
// c = [ so create new segment
// counts = {2};
// segments = {"AB","CDCDCD", ""}
//
// 11th
// c = 2 so push to counts stack
// counts = {2,2}
// segment = {"AB","CDCDCD",""};
//
// 12th and 13th
// c = E, c = F so push to top segment
// counts = {2,2}
// segments = {"AB","CDCDCD","EF"}
//
// 14th
// c = ]
// get top multiple and top segment then iterate and add substring to
// top segment
//
// counts = {2}
// segments = {"AB","CDCDCDEFEF"}
//
// 15th
// c = ]
// get top multiple and top segment then iterate and add substring to
// top segment
//
// counts = {};
// segments = {"ABCDCDCDEFEFCDCDCDEFEF"};
//
// Finish iterations so return top segments
// Output: "ABCDCDCDEFEFCDCDCDEFEF";
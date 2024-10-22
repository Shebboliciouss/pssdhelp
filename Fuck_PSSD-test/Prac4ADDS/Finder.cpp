#include "Finder.h"
#include <unordered_map>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
  vector<int> result;
  unordered_map<char, vector<int>> char_map;

  int s2Size = s2.length();

  for (int i = 0; i < s1.length(); i++) {
    char_map[s1[i]].push_back(i);
  }

  vector<int> pre_vector = char_map[s2[0]];
  int counter = pre_vector.size();
  if (counter > 0) {
    result.push_back(pre_vector[0]);
  }

  string s2Substring = "";
  s2Substring.push_back(s2[0]);
  int pre_counter = 1;

  while (pre_counter <= s2Size) {
    s2Substring += s2[pre_counter];
    pre_counter++;

    for (int i = 0, j = 0; i < pre_counter; i++) {
      int curr_ind = pre_vector[j];
      while (s2Substring[i] == s1[curr_ind]) {
        i++;
        curr_ind++;
        if (i < pre_counter && j < counter && s2Substring[i] != s1[curr_ind]) {
          i = 0;
          j++;
          curr_ind = pre_vector[j];
        }
      }

      if (i >= pre_counter && j < counter) {
        result.push_back(pre_vector[j]);
      }
    }
  }

  int remaining = pre_counter - result.size() - 1;
  for (int i = 0; i < remaining; i++) {
    result.push_back(-1);
  }

  return result;
}

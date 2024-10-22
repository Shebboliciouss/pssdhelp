CORRUPTEDMESSAGE
Problem Details

There are 26 options for the lower case letter that makes the whole message. What we can do is try each letter ch and count the number of characters that are different to ch in the input. If the number of different characters is K, then we are alowed to say that a string of n times the ch letter is a possible result. We can print any of those results.

It is worth nothing that the letter in question might not appear in the input string, like in example 1).

In languages like Java or c++ , the characters behave as/are integers and we can do a loop from ‘a’ to ‘z’:

string reconstructMessage(string s, int k) {
  char res = 'z';
  // if the result is none of those between a and y, then return z:
  for (char ch = 'a'; ch <= 'y'; ch++) {
    // count differences:
    int d = 0;
    for (char x: s) {
      if (x != ch) {
        d++;
      }
    }
    if (d == k) {
      res = ch; //match
    }
  }
  // make string of s.size() result characters:
  return string(s.size(), res);
}
Or you may have to convert between characters and integers and back. Like in this python solution:

class CorruptedMessage:
  def reconstructMessage(self, s, k):
  for i in range(ord('a'), ord('z') + 1):
  ch = chr(i)
if sum(x != ch
    for x in s) == k:
  return ch * len(s)
return '!'
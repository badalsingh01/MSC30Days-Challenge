//https://leetcode.com/problems/reverse-words-in-a-string/
//problem 151 leetcode
class Solution {
 public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());        
    reverseWords(s, s.length());        
    return cleanSpaces(s, s.length());  
  }

 private:
  void reverseWords(string& s, int n) {
    int i = 0;
    int j = 0;

    while (i < n) {
      while (i < j || i < n && s[i] == ' ')  
        ++i;
      while (j < i || j < n && s[j] != ' ')  
        ++j;
      reverse(s.begin() + i, s.begin() + j);  
    }
  }

  string cleanSpaces(string& s, int n) {
    int i = 0;
    int j = 0;

    while (j < n) {
      while (j < n && s[j] == ' ')  
        ++j;
      while (j < n && s[j] != ' ')  
        s[i++] = s[j++];
      while (j < n && s[j] == ' ')  
        ++j;
      if (j < n)  
        s[i++] = ' ';
    }

    return s.substr(0, i);
  }
};
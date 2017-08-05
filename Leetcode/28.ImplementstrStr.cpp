#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    int i = 0, j = 0;
    int m = haystack.size(), n = needle.size();
    while(i <= (m - n)) {
      j = 0;
      while(haystack[i] == needle[j]) {
        i++;
        j++;
        if (j == n) {
          return (i - n);
        }
      }
      i = i - j + 1;
    }
    return -1;
  }
};

int main() {
  string a = "123";
  string b = "000";
  cout << Solution().strStr(a, b) << endl;
  return 0;
}
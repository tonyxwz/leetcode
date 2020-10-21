/* Input: "A man, a plan, a canal: Panama" */
/* Output: true */
#include <cctype>
#include <string>

using namespace std;

class Solution
{
  static bool same(char a, char b)
  {
    if (isalpha(a) && isalpha(b))
      return toupper(a) == toupper(b);
    else
      return a == b;
  }

public:
  bool isPalindrome(string s)
  {
    int l = 0;
    int r = s.length() - 1;
    bool ans = true;
    while (l < r) {
      if (!isalnum(s[l])) {
        l++;
        continue;
      }
      if (!isalnum(s[r])) {
        r--;
        continue;
      }
      ans = ans && same(s[l], s[r]);
      if (!ans)
        break;
      l++;
      r--;
    }
    return ans;
  }
};

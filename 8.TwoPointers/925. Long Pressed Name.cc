class Solution
{
public:
  bool isLongPressedName(string name, string typed)
  {
    int p1 = 0;
    int p2 = 0;
    while (p2 < typed.size()) {
      if (name[p1] == typed[p2]) {
        p1++;
        p2++;
      } else {
        if (p2 > 0 && p1 > 0 && typed[p2] == typed[p2 - 1] &&
            typed[p2] == name[p1 - 1]) {
          p2++;
        } else {
          return false;
        }
      }
    }
    return p1 == name.size();
  }
};

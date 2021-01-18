#include "ch2.hpp"

inline bool
pos_ok(int pos)
{
  if (pos <= 0 || pos > 64) {
    cerr << "Invalid position " << pos << endl;
    return false;
  } else {
    return true;
  }
}

bool
calc_pentagonal(vector<int>& a, int pos)
{
  if (!pos_ok(pos))
    return false;
  else {
    for (int i = a.size() + 1; i <= pos; ++i)
      a.push_back(i * (3 * i - 1) / 2);
    return true;
  }
}

void
display(string& title, vector<int>& a, ostream& os = cout)
{
  os << title << endl;
  for (const auto i : a)
    os << i << " ";
  os << endl;
}

int
main()
{
  string title = "Pentagonal Sequence";
  vector<int> pent;
  if (!calc_pentagonal(pent, 50))
    return 1;
  display(title, pent);
  return 0;
}
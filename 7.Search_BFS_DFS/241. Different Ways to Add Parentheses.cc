#include <functional>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


// nice memoized function design (one benefit of using C++ and OOP)
// recursively parse the expression into only two components and combine
class Solution
{
private:
  // memoized function
  const map<char, std::function<int(int, int)>> ops{
    { '*', std::multiplies<int>() },
    { '+', std::plus<int>() },
    { '-', std::minus<int>() }
  };
  unordered_map<string, vector<int>> mem;

  const vector<int>& parse(string input)
  {
    if (mem.count(input))
      return mem.at(input);
    vector<int> ans;

    for (int i = 0; i < input.length(); i++) {
      const char op = input[i];
      if (op == '+' || op == '-' || op == '*') {
        const string lhs = input.substr(0, i);
        const string rhs = input.substr(i + 1);

        const vector<int>& left = parse(lhs);
        const vector<int>& right = parse(rhs);

        for (int l : left)
          for (int r : right)
            ans.push_back(ops.at(op)(l, r));
      }
    }
    if (ans.empty())
      ans.push_back(stoi(input));
    mem[input].swap(ans);
    return mem[input];
  }

public:
  vector<int> diffWaysToCompute(string input) { return parse(input); }
};


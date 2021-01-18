#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<std::string, int>
mapFromTxt(const char* filename, const std::set<std::string>& exclude);
void
cleanupWord(std::string& word);

int
main(int argc, char* argv[])
{
  using namespace std;
  std::set<std::string> exclude{ "but", "and", "or", "a", "an", "the" };
  if (argc > 1) {
    auto results = mapFromTxt(argv[1], exclude);
    for (const auto& p : results)
      cout << p.first << ": " << p.second << endl;
  } else {
    return 1;
  }
}

void
cleanupWord(std::string& word)
{
  // 1 replace spacial chars with space
  // 2 trim word
}

std::unordered_map<std::string, int>
mapFromTxt(const char* filename, const std::set<std::string>& exclude)
{
  using namespace std;

  unordered_map<string, int> results;

  ifstream in_file(filename);

  if (!in_file) {
    cerr << "error reading file: " << filename << endl;
    return results;
  }

  /* istream_iterator<string> iter_begin(in_file); */
  /* istream_iterator<string> eof; */
  /* copy(iter_begin, eof, ) */

  string word;
  while (in_file >> word) {
    if (!exclude.count(word))
      ++results[word];
  }

  return results;
}

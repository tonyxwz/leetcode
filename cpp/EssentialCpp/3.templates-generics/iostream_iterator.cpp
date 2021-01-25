#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

void method1() {
  string word;
  vector<string> text;
  while(cin >> word)
    text.push_back(word);

  sort(text.begin(), text.end());

  for(const auto &s: text)
    cout << s << " ";
}

void method2() {
  istream_iterator<string> is(cin);
  istream_iterator<string> eof;

  vector<string> text;
  copy(is, eof, back_inserter(text));

  sort(text.begin(), text.end());
  ostream_iterator<string> os(cout, " ");
  copy(text.begin(), text.end(), os);
}


void rw2file() {
  ifstream in_file("input_file.txt");
  ofstream out_file("output_file.txt");

  if (!in_file || !out_file)
    cerr << "error reading file" << endl;

  istream_iterator<string> is(in_file);
  istream_iterator<string> eof;

  vector<string> text;
  copy(is, eof, back_inserter(text));

  sort(text.begin(), text.end());
  ostream_iterator<string> os(out_file, " ");
  copy(text.begin(), text.end(), os);
}

int main() {
  rw2file();
  return 0;
}

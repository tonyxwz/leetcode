#include "leetcode.h"

// the question asks for the shortest path, thus BFS
// normal BFS
// Author: Huahua
// Running Time: 216 ms (better than 65.42%)
class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord,
                                     string endWord,
                                     vector<string>& wordList)
  {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
      return {};
    dict.erase(beginWord);
    dict.erase(endWord);

    const int N = beginWord.length();

    unordered_map<string, int> steps{ { beginWord, 1 } };
    unordered_map<string, vector<string>> parents;
    int step = 0;

    queue<string> q;
    q.push(beginWord);

    bool found = false;

    while (!q.empty() && !found) {
      ++step;
      for (int size = q.size(); size > 0; --size) {
        const string p = q.front();
        q.pop();
        string w = p;
        for (int i = 0; i < N; ++i) {
          const char ch = w[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c == ch)
              continue;
            w[i] = c;
            if (w == endWord) {
              // endword is not in dict any more, handled here
              parents[w].push_back(p);
              found = true;
            } else {
              if (steps.count(w) && step < steps.at(w)) {
                //
                parents[w].push_back(p);
              }
            }
            if (!dict.count(w))
              continue;
            dict.erase(w);
            q.push(w);
            steps[w] = steps[p] + 1;
            parents[w].push_back(p);
          }
          w[i] = ch;
        }
      }
    }
    vector<vector<string>> ans;
    if (found) {
      vector<string> curr{ endWord };
      getPaths(endWord, beginWord, parents, curr, ans);
    }
    return ans;
  }

  vector<vector<string>> bidirectionalBFS(string beginWord,
                                          string endWord,
                                          vector<string>& wordList)
  {
    vector<vector<string>> ans;
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (!dict.count(endWord))
      return ans;

    const int l = beginWord.length();
    unordered_set<string> q1{ beginWord };
    unordered_set<string> q2{ endWord };
    unordered_map<string, vector<string>> children;

    bool found = false;
    bool backward = false;

    while (!q1.empty() && !q2.empty() && !found) {
      if (q1.size() > q2.size()) {
        q1.swap(q2);
        backward = !backward;
      }
      for (const string& w : q1)
        dict.erase(w);
      // for (const string& w : q2)
      //   dict.erase(w);

      unordered_set<string> q;

      for (const string& word : q1) {
        string w = word; // word is still needed to build the children map
        for (int i = 0; i < l; i++) {
          const char ch = w[i];
          for (char c = 'a'; c <= 'z'; c++) {
            if (ch == c)
              continue;
            w[i] = c;
            const string* parent = &word;
            const string* child = &w;
            if (backward)
              std::swap(parent, child);
            if (q2.count(w)) {
              // bidirectionaly growing, find existance of new word in the other
              // side (layer). if exists: the this is the shortest path and
              // stop going deeper
              found = true;
              children[*parent].push_back(*child);
            } else if (dict.count(w)) {
              children[*parent].push_back(*child);
              q.insert(w);
            }
          }
          w[i] = ch;
        }
      }
      q1.swap(q);
    }
    if (found) {
      vector<string> curr{ beginWord };
      buildForward(beginWord, endWord, children, curr, ans);
    }
    return ans;
  }

private:
  void buildForward(const string& word,
                    const string& endWord,
                    const unordered_map<string, vector<string>>& children,
                    vector<string>& curr,
                    vector<vector<string>>& ans)
  {
    if (word == endWord) {
      ans.push_back(curr);
      return;
    }

    const auto it = children.find(word);
    if (it == children.cend())
      return;

    for (const string& child : it->second) {
      curr.push_back(child);
      buildForward(child, endWord, children, curr, ans);
      curr.pop_back();
    }
  }

  void getPaths(const string& word,
                const string& beginWord,
                const unordered_map<string, vector<string>>& parents,
                vector<string>& curr,
                vector<vector<string>>& ans)
  {

    if (word == beginWord) {
      ans.emplace_back(curr.rbegin(), curr.rend());
      return;
    }

    for (const string& p : parents.at(word)) {
      curr.push_back(p);
      getPaths(p, beginWord, parents, curr, ans);
      curr.pop_back();
    }
  }
};

int
main()
{
  string from = "cet";
  string to = "ism";
  vector<string> wordlist{
    "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip",
    "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die",
    "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot",
    "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad",
    "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis",
    "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box",
    "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam",
    "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim",
    "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye",
    "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot",
    "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel",
    "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom",
    "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit",
    "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron",
    "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop",
    "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod",
    "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie",
    "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod",
    "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm",
    "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx",
    "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom",
    "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas",
    "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy",
    "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava",
    "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd",
    "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw",
    "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any",
    "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao",
    "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass",
    "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen",
    "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix",
    "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye",
    "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon",
    "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep",
    "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig",
    "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit",
    "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet",
    "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw",
    "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt",
    "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil",
    "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig",
    "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two",
    "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun",
    "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way",
    "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah",
    "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was",
    "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab",
    "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac",
    "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig",
    "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref",
    "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo",
    "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup",
    "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len",
    "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee",
    "pin", "dun", "pat", "ten", "mob"
  };
  // string from = "red";
  // string to = "tax";
  // vector<string> wordlist{"ted","red",
  // "tex","red","tax","tad","den","rex","pee"};

  Solution s;
  auto ans = s.bidirectionalBFS(from, to, wordlist);
  for (auto v : ans) {
    cout << "[ ";
    for (auto s : v) {
      cout << s << " ";
    }
    cout << "]" << endl;
  }
}

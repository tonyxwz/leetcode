class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0; 
        int r = S.length()-1;
        while(l < r) {
          if(!isalpha(S[l])){
            l++;
            continue;
          }
          if(!isalpha(S[r])) {
            r--;
            continue;
          }
          std::swap(S[l], S[r]);
          l++;
          r--;
        }
        return S;
    }
};

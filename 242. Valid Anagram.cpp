#include <bits/stdc++.h>
using namespace std;
class Solution { public: bool isAnagram(string s, string t){ if(s.size()!=t.size()) return false; int cnt[26]={0}; for(char c: s) cnt[c-'a']++; for(char c: t) cnt[c-'a']--; for(int i=0;i<26;i++) if(cnt[i]) return false; return true; } };

#include <bits/stdc++.h>
using namespace std;
class Solution {
    int expand(const string& s, int l, int r){ int cnt=0; while(l>=0 && r<(int)s.size() && s[l]==s[r]){ cnt++; l--; r++; } return cnt; }
public:
    int countSubstrings(string s) {
        int n=s.size(), ans=0; for(int i=0;i<n;i++){ ans+=expand(s,i,i); ans+=expand(s,i,i+1);} return ans;
    }
};

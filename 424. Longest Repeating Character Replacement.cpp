#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26,0); int best=0, l=0, maxc=0;
        for(int r=0;r<(int)s.size();++r){ maxc=max(maxc, ++cnt[s[r]-'A']); while(r-l+1-maxc>k){ cnt[s[l]-'A']--; l++; } best=max(best, r-l+1); }
        return best;
    }
};

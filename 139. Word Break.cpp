#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n=s.size(); vector<char> dp(n+1,false); dp[0]=true;
        int maxLen=0; for(auto& w: wordDict) maxLen=max(maxLen,(int)w.size());
        for(int i=1;i<=n;i++){
            for(int l=1;l<=maxLen && l<=i;l++){
                if(dp[i-l] && dict.count(s.substr(i-l,l))){ dp[i]=true; break; }
            }
        }
        return dp[n];
    }
};

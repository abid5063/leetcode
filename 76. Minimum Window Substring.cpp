#include <bits/stdc++.h>
using namespace std;
class Solution { public: string minWindow(string s, string t){ if(t.empty()) return ""; vector<int> need(128,0); for(char c: t) need[(int)c]++; int required=t.size(); int l=0, bestLen=INT_MAX, bestL=0; for(int r=0;r<(int)s.size();++r){ if(need[(int)s[r]]>0) required--; need[(int)s[r]]--; while(required==0){ if(r-l+1<bestLen){ bestLen=r-l+1; bestL=l; } need[(int)s[l]]++; if(need[(int)s[l]]>0) required++; l++; } } return bestLen==INT_MAX?"":s.substr(bestL,bestLen); } };

#include <bits/stdc++.h>
using namespace std;
class Solution { public: vector<vector<int>> merge(vector<vector<int>>& a){ if(a.empty()) return {}; sort(a.begin(), a.end()); vector<vector<int>> res; res.push_back(a[0]); for(size_t i=1;i<a.size();++i){ if(a[i][0] <= res.back()[1]) res.back()[1] = max(res.back()[1], a[i][1]); else res.push_back(a[i]); } return res; } };

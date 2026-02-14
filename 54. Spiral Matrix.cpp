#include <bits/stdc++.h>
using namespace std;
class Solution { public: vector<int> spiralOrder(vector<vector<int>>& m){ vector<int> res; if(m.empty()) return res; int top=0, left=0, bottom=m.size()-1, right=m[0].size()-1; while(top<=bottom && left<=right){ for(int j=left;j<=right;j++) res.push_back(m[top][j]); top++; for(int i=top;i<=bottom;i++) res.push_back(m[i][right]); right--; if(top<=bottom){ for(int j=right;j>=left;j--) res.push_back(m[bottom][j]); bottom--; } if(left<=right){ for(int i=bottom;i>=top;i--) res.push_back(m[i][left]); left++; } } return res; } };

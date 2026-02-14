#include <bits/stdc++.h>
using namespace std;
class Solution { void dfs(vector<vector<char>>& g, int i, int j){ int n=g.size(), m=g[0].size(); if(i<0||j<0||i>=n||j>=m||g[i][j]!='1') return; g[i][j]='0'; dfs(g,i+1,j); dfs(g,i-1,j); dfs(g,i,j+1); dfs(g,i,j-1);} public: int numIslands(vector<vector<char>>& g){ if(g.empty()) return 0; int n=g.size(), m=g[0].size(), c=0; for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j]=='1'){ c++; dfs(g,i,j);} return c; } };

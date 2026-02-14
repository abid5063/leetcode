#include <bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i,int j, vector<vector<int>>& h, vector<vector<char>>& vis){
        int n=h.size(), m=h[0].size(); vis[i][j]=1;
        static int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto &k: d){ int ni=i+k[0], nj=j+k[1]; if(ni>=0&&nj>=0&&ni<n&&nj<m && !vis[ni][nj] && h[ni][nj]>=h[i][j]) dfs(ni,nj,h,vis); }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(); if(!n) return {}; int m=heights[0].size();
        vector<vector<char>> pac(n, vector<char>(m,0)), atl(n, vector<char>(m,0));
        for(int i=0;i<n;i++){ dfs(i,0,heights,pac); dfs(i,m-1,heights,atl);} 
        for(int j=0;j<m;j++){ dfs(0,j,heights,pac); dfs(n-1,j,heights,atl);} 
        vector<vector<int>> res; for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(pac[i][j] && atl[i][j]) res.push_back({i,j});
        return res;
    }
};

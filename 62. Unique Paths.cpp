// Problem (short):
// Given a grid size m by n, return how many ways exist to move from top-left to bottom-right using only right and down.

#include <bits/stdc++.h>

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(m, vector<int>(n,0));
        res[0][0]=1;
        for(int i=0; i< m ;i++){
            for(int j=0; j<n; j++){
                if (i>0){
                    res[i][j]+=res[i-1][j];
                }
                if (j>0){
                    res[i][j]+=res[i][j-1];

                }
  
            }
        }
        return res[m-1][n-1];
    }
};
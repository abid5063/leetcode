#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(n+1,0); 
      
      if (n==1) return 1; 
      
        ans[1]=1;
        ans[2]=2;

        for (int i=3; i<=n; i++){
            ans[i]= ans[i-2]+ ans[i-1];
        }
        return ans[n];
    }
};
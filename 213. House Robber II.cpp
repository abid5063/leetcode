#include <bits/stdc++.h>
using namespace std;
class Solution {
    int robLine(vector<int>& nums, int l, int r){ int p2=0, p1=0; for(int i=l;i<=r;i++){ int cur=max(p1, p2+nums[i]); p2=p1; p1=cur; } return p1; }
public:
    int rob(vector<int>& nums){ int n=nums.size(); if(n==1) return nums[0]; return max(robLine(nums,0,n-2), robLine(nums,1,n-1)); }
};

// Problem (short):
// Given a rotated sorted array and a target, return the target index or -1.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l,r,m; 
        l=0; r=nums.size()-1;
        while( l< r){
            m=(l+r)/2;
            if(target== nums[m]){
                return m;
            }

            else if(nums[m]<nums[r]){
                if(nums[m]<target && target <= nums[r])l=m+1;
                else r=m-1;
            }
            else{
                if(nums[l]<= target && target <nums[m])r=m-1;
                else l=m+1;

            }
        }
        if(nums[l]==target)
            return l;
        else 
            return -1;
    }
};

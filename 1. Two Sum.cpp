// Problem (short):
// Given an array and a target, return the indices of two numbers that add up to the target.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> idx;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            if (idx.count(need)) return {idx[need], i};
            idx[nums[i]] = i;
        }
        return {};
    }
};

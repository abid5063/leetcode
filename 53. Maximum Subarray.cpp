// Problem (short):
// Given an array, return the largest sum of any contiguous subarray.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
int maxSubArray(vector<int>& nums) {
    int best = INT_MIN;
    int sum = 0;

    for (int x : nums) {
        sum += x;                // extend current subarray
        best = max(best, sum);   // record best seen so far
        if (sum < 0) sum = 0;    // negative prefix hurts future, drop it
    }
    return best;
}
};

// Problem (short):
// Given money in houses in a line, return the maximum amount you can rob without robbing adjacent houses.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev2 = 0, prev1 = 0;
        for (int x : nums)
        {
            int cur = max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

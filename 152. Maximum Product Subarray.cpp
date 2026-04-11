// Problem (short):
// Given an array, return the maximum product of any contiguous subarray.



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];
            int prevMax = curMax;
            int prevMin = curMin;

            curMax = max({x, x * prevMax, x * prevMin});
            curMin = min({x, x * prevMax, x * prevMin});
            best = max(best, curMax);
        }

        return best;
    }
};

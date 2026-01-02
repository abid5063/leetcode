#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize current max, current min, and global max to the first element
        int cur_max = nums[0];
        int cur_min = nums[0];
        int global_max = nums[0];

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current number is negative, swap cur_max and cur_min
            // because multiplying by a negative flips max/min
            if (nums[i] < 0) {
                swap(cur_max, cur_min);
            }
            // Update cur_max and cur_min
            cur_max = max(nums[i], cur_max * nums[i]);
            cur_min = min(nums[i], cur_min * nums[i]);
            // Update global_max if needed
            global_max = max(global_max, cur_max);
        }
        // Return the largest product found
        return global_max;
    }
};

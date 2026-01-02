#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize max_sum and current_sum to the first element
        int max_sum = nums[0];
        int current_sum = nums[0];
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // Update current_sum: either start a new subarray at nums[i] or extend the previous subarray
            current_sum = max(nums[i], current_sum + nums[i]);
            // Update max_sum if current_sum is greater
            max_sum = max(max_sum, current_sum);
        }
        // Return the largest sum found
        return max_sum;
    }
};
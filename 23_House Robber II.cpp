#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return nums[0];
		// Helper to run House Robber DP on a subarray
		auto robLinear = [](vector<int>& arr, int start, int end) {
			int prev1 = 0, prev2 = 0;
			for (int i = start; i < end; ++i) {
				int cur = max(prev1, prev2 + arr[i]);
				prev2 = prev1;
				prev1 = cur;
			}
			return prev1;
		};
		// Exclude last house
		int rob1 = robLinear(nums, 0, n - 1);
		// Exclude first house
		int rob2 = robLinear(nums, 1, n);
		return max(rob1, rob2);
	}
};

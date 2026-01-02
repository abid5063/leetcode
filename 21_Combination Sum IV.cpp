#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<long long> dp(target + 1, 0); // Use long long to avoid overflow
		dp[0] = 1;
		for (int i = 1; i <= target; ++i) {
			for (int num : nums) {
				if (i - num >= 0) {
					if (dp[i] > LLONG_MAX - dp[i - num]) {
						dp[i] = LLONG_MAX; // Prevent overflow
					} else {
						dp[i] += dp[i - num];
					}
				}
			}
		}
		// If result exceeds INT_MAX, return -1 to indicate overflow
		return dp[target] > INT_MAX ? -1 : (int)dp[target];
	}
};

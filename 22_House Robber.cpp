#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int prev1 = 0, prev2 = 0;
		for (int num : nums) {
			int cur = max(prev1, prev2 + num); // Rob current or skip
			prev2 = prev1;
			prev1 = cur;
		}
		return prev1;
	}
};

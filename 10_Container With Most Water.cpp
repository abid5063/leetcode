#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int max_area = 0;
		// Use two pointers to find the largest area
		while (left < right) {
			int h = min(height[left], height[right]);
			int w = right - left;
			max_area = max(max_area, h * w);
			// Move the pointer pointing to the shorter line inward
			if (height[left] < height[right]) {
				++left;
			} else {
				--right;
			}
		}
		return max_area;
	}
};

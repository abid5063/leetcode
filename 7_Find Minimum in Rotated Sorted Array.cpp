#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // Binary search for the minimum element
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // If mid element is greater than right, min is in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // Min is in left half (including mid)
                right = mid;
            }
        }
        // After loop, left == right and points to minimum
        return nums[left];
    }
};
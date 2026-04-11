// Problem (short):
// Given distinct numbers and a target, return how many ordered combinations sum to the target.

/*
377. Combination Sum IV

Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:
Input: nums = [9], target = 3
Output: 0

Constraints:
- 1 <= nums.length <= 200
- 1 <= nums[i] <= 1000
- All the elements of nums are unique.
- 1 <= target <= 1000
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Approach 1: Dynamic Programming (Bottom-up)
    // Time: O(target * n), Space: O(target)
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1; // Base case: one way to make 0 (empty combination)
        
        // For each sum from 1 to target
        for (int sum = 1; sum <= target; sum++) {
            // Try using each number
            for (int num : nums) {
                if (sum >= num) {
                    dp[sum] += dp[sum - num];
                }
            }
        }
        
        return dp[target];
    }
    
    // Approach 2: Memoization (Top-down)
    // Time: O(target * n), Space: O(target)
    int combinationSum4_memo(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return helper(nums, target, memo);
    }
    
private:
    int helper(vector<int>& nums, int target, unordered_map<int, int>& memo) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        
        if (memo.find(target) != memo.end()) {
            return memo[target];
        }
        
        int result = 0;
        for (int num : nums) {
            result += helper(nums, target - num, memo);
        }
        
        memo[target] = result;
        return result;
    }
};

/*
Key Insights:
1. This is a "combination with repetition allowed and order matters" problem
   - Different from regular combination sum where order doesn't matter
   - Similar to coin change II but ORDER MATTERS here

2. Dynamic Programming approach:
   - dp[i] = number of combinations to make sum i
   - For each target sum, try adding each number from nums
   - dp[sum] += dp[sum - num] for all valid num

3. The outer loop MUST be on target sum (not on numbers)
   - This ensures different orders are counted
   - If we loop numbers first, we'd count permutations incorrectly

4. Use unsigned int to avoid integer overflow issues
   - Problem guarantees answer fits in 32-bit integer
   - But intermediate sums might overflow signed int

5. Time Complexity: O(target * n) where n = nums.length
   Space Complexity: O(target)

Example Trace for nums = [1,2,3], target = 4:
dp[0] = 1
dp[1] = dp[0] = 1                    // [1]
dp[2] = dp[1] + dp[0] = 2            // [1,1], [2]
dp[3] = dp[2] + dp[1] + dp[0] = 4    // [1,1,1], [1,2], [2,1], [3]
dp[4] = dp[3] + dp[2] + dp[1] = 7    // [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2], [1,3], [3,1]
*/



#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // If current number is negative, swap max and min
            // because multiplying by negative flips the sign
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            
            // Update max and min products ending at current position
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            
            // Update global maximum
            result = max(result, maxProd);
        }
        
        return result;
    }
};

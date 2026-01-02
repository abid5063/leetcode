
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; 

        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            int complement = target - currentNum;

            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }

            numMap[currentNum] = i;
        }

        return {}; 
    }
};




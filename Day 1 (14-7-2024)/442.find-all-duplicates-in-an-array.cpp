/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int num = abs(nums[i]);
            if(nums[num - 1] < 0) 
                ans.push_back(num);
            else nums[num - 1] *= -1;
        }
        return ans;
    }
};
// @lc code=end


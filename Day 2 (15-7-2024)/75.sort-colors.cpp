/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0, p2 = 0, p3 = nums.size() - 1;
        while(p2 <= p3){
            if(nums[p2] == 0) swap(nums[p1++], nums[p2++]);
            else if(nums[p2] == 2) swap(nums[p2], nums[p3--]); //dont increment p2;
            else p2++;
        }
    }
};
// @lc code=end


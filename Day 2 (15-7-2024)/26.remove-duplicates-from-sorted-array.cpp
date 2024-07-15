/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0, p2 = 1, n = size(nums);
        while(p2 < n){
            while(p2 < n and nums[p2] == nums[p1]) p2++;
            if(p2 < n and p1 + 1 < n){
                p1++;
                nums[p1] = nums[p2];
            }
        }
        return p1 + 1;
    }
};
// @lc code=end


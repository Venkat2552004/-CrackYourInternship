/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), p1 = 0, p2 = 0;
        while(p1 < n and nums[p1] != 0){
            p1++;
        }
        p2 = p1 + 1;
        while(p2 < n){
            if(nums[p2] != 0){
                nums[p1] = nums[p2];
                p1++;
            }
            p2++;
        }
        while(p1 < n) nums[p1++] = 0;
    }
};
// @lc code=end


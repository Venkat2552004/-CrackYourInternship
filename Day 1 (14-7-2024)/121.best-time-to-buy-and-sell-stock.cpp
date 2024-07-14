/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(int num : prices){
            mini = min(mini, num);
            ans = max(ans, num - mini);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &arr){
        vector<int> ans;
        int n = arr.size();
        int m = arr[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (top <= bottom && left <= right){
            for (int j = left; j <= right; ++j)
                ans.push_back(arr[top][j]);
            ++top;
            for (int i = top; i <= bottom; ++i)
                ans.push_back(arr[i][right]);
            --right;
            if (top <= bottom){
                for (int j = right; j >= left; --j)
                    ans.push_back(arr[bottom][j]);
                --bottom;
            }
            if (left <= right){
                for (int i = bottom; i >= top; --i)
                    ans.push_back(arr[i][left]);
                ++left;
            }
        }
        return ans;
    }
};
// @lc code=end


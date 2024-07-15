/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int p1 = 0, n = size(arr), p2 = n - 1;
        int area = 0;
        while (p1 < p2){
            area = max(area, min(arr[p1], arr[p2]) * (p2 - p1));
            if(arr[p1] <= arr[p2]) p1++;
            else p2--;
        }
        return area;
    }
};
// @lc code=end


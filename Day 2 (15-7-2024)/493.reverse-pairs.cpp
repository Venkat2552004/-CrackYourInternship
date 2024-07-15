/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
class Solution {
public:
    int ans = 0;
    int reversePairs(vector<int>& nums) {
        int n = size(nums);
        sect(0, n - 1, nums);
        return ans;
    }

    void sect(int i, int j, vector<int>& nums){
        if(i >= j) return;
        int mid = (i + j) / 2;
        sect(i, mid, nums);
        sect(mid + 1, j, nums);
        solve(i, mid, j, nums, ans);
    }

    void solve(int l, int m, int h, vector<int>& nums, int &ans){
        int i = l, j = m + 1;
        while(i <= m and j <= h){
            if(nums[i] > 2LL * nums[j]){
                ans += (m - i + 1);
                j++;
            }
            else i++;
        }
        merge(l, m, h, nums);
    }

    void merge(int l, int m, int h, vector<int>& nums){
        vector<int> temp(h - l + 1);
        int i = l, j = m + 1, k = 0;
        while(i <= m and j <= h){
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        while(i <= m)
            temp[k++] = nums[i++];
        while(j <= h)
            temp[k++] = nums[j++];

        for(int i = l; i <= h; i++){
            nums[i] = temp[i - l];
        }
    }
};
// @lc code=end


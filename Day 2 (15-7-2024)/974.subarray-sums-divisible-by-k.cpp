/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        mp[0]++;
        for(int num : nums){
            sum += num;
            int mod = sum % k;
            if(mod < 0) mod += k;
            if(mp[mod] > 0){
                ans += mp[mod];
            }
            mp[mod]++;
        }
        return ans;
    }
};
// @lc code=end


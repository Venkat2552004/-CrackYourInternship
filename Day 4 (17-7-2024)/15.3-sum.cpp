/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> s;
        int n = size(arr);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n - 2; i++){
            int t = -arr[i];
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                int sum = arr[j] + arr[k];
                if(sum == t){
                    s.insert({arr[i], arr[j], arr[k]});
                    j++, k--;
                }
                else if(sum < t) j++;
                else k--;
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
// @lc code=end


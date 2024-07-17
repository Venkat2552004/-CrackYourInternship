/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = size(arr);
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                long long k = (long long)target - (long long)arr[i] - (long long)arr[j];
                int l = j + 1, h = n - 1;
                while(l < h){
                    long long sum = arr[l] + arr[h];
                    if(sum == k){
                        ans.push_back({arr[i], arr[j], arr[l], arr[h]});
                        int idx1 = l, idx2 = h;
                        while(l < h and arr[idx1] == arr[l]) l++;
                        while(l < h and arr[idx2] == arr[h]) h--;
                    }
                    else if(sum < k) l++;
                    else h--;
                }
                while(j < n - 2 and arr[j] == arr[j + 1]) j++;
            }
            while(i < n - 1 and arr[i] == arr[i + 1]) i++;
        }
        return ans;
    }
};
// @lc code=end


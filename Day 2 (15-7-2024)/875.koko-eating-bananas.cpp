/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& arr, int hours) {
        int n = size(arr);
        int l = 1;
        int h = *max_element(arr.begin(), arr.end());
        int ans = INT_MAX;
        while(l <= h){
            int mid = (l + h) / 2;
            if(valid(arr,n, hours, mid)){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }

    bool valid(vector<int>& arr,int n, int h, int k){
        for(int i = 0; i < n; i++){
            if(arr[i] <= k){
                h = h - 1;
            }
            else{
                if(arr[i] % k == 0) h -= (arr[i] / k);
                else h -= (arr[i] /k) + 1;
            }
        }
        return h >= 0;
    }
};
// @lc code=end


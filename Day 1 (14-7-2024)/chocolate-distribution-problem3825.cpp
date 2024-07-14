class Solution{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        // code
        sort(a.begin(), a.end());
        long long ans = INT_MAX;
        for (int i = m - 1; i < n; i++){
            ans = min(ans, a[i] - a[i - m + 1]);
        }
        return ans;
    }
};
/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    void gameOfLife(vector<vector<int>>& arr) {
        int n = size(arr);
        int m = size(arr[0]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = liveCount(arr, i, j, n, m);
                if(arr[i][j] == 0 and cnt == 3)
                    arr[i][j] = -1;
                else if(arr[i][j] == 1 and (cnt < 2 or cnt > 3))
                    arr[i][j] = 2;
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                arr[i][j] = abs(arr[i][j]) % 2;
    }

    int liveCount(vector<vector<int>>&arr, int i, int j, int n, int m){
        int cnt = 0;
        for(auto p : dir){
            int a = i + p.first;
            int b = j + p.second;
            if(a >= 0 and a < n and b >= 0 and b < m)
                if(arr[a][b] == 1 or arr[a][b] == 2) cnt++;
        }
        return cnt;
    }
};
// @lc code=end


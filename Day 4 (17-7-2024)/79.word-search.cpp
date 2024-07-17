/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = size(board);
        int n = size(board[0]);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isExist(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool isExist(vector<vector<char>>& board, int i, int j, string word, int idx){
        if(idx == word.length()) return true;
        int m = size(board);
        int n = size(board[0]);
        if(i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[idx]) return false;
        char x = board[i][j];
        board[i][j] = '#';
        if (isExist(board, i - 1, j, word, idx + 1) or isExist(board, i + 1, j, word, idx + 1) or isExist(board, i, j - 1, word, idx + 1) or isExist(board, i, j + 1, word, idx + 1))
            return true;
        board[i][j] = x;
        return false;
    }
};
// @lc code=end


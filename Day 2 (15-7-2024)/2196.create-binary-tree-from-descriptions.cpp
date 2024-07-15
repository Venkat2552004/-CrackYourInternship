/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> mp;
        set<int> p, c;
        int n = size(desc);
        TreeNode* root = NULL;
        for(int i = 0; i < n; i++){
            int x = desc[i][0];
            int y = desc[i][1];
            int z = desc[i][2];
            if(mp.find(x) == mp.end())
                mp[x] = new TreeNode(x);
            if(mp.find(y) == mp.end())
                mp[y] = new TreeNode(y);
            if(z == 1)
                mp[x]->left = mp[y];
            else
                mp[x]->right = mp[y];
            
            p.insert(x);
            c.insert(y);
        }

        for(int x : p){
            if(c.find(x) == c.end()){
                root = mp[x];
                break;
            }
        }
        return root;
    }


};
// @lc code=end


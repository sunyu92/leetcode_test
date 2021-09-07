/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        string path;

        if ( root == nullptr )
        {
            return result;
        }

        traversal( root, path, result );
        return result;
    }

private:
    void traversal (TreeNode* cur, string path, vector<string>& result)
    {
        path += to_string( cur->val );  // 中

        if ( cur->left == nullptr && cur->right == nullptr )
        {
            result.emplace_back(path);
            return;
        }

        if ( cur->left )
        {
            traversal( cur->left, path+"->", result );      // 左
        }

        if ( cur->right )
        {
            traversal( cur->right, path+"->", result );     // 右
        }

    }

};
// @lc code=end


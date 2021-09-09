/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {

        // 判空
        if (root == nullptr)
        {
            return 0;
        }

        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);

        while (!q.empty())
        {
            TreeNode* cur = q.front().first;
            int depth = q.front().second;
            q.pop();

            // 找到答案
            if (cur->left == nullptr && cur->right == nullptr)
            {
                return depth;
            }

            if (cur->left != nullptr)
            {
                q.emplace(cur->left, depth + 1);
            }

            if (cur->right != nullptr)
            {
                q.emplace(cur->right, depth + 1);
            }
        }
        return 0;
    }
};
// @lc code=end


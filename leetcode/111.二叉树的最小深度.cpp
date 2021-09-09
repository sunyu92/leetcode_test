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
        if ( root == nullptr)
        {
            return 0;
        }

        queue<pair<TreeNode*, int>> que;    // 队列，先进先出；只允许在队首删除（出队），队尾插入（入队)
        que.emplace(root, 1);   // root 本身就是一层,depth 初始化为 1

        while(!que.empty())
        {
            TreeNode* current_node = que.front().first;     // 取数
            int depth = que.front().second;
            que.pop();      // 删除

            // 判断是否到达终点
            if (current_node->left == nullptr && current_node->right == nullptr)
            {
                return depth;
            }

            // 将 cur 的相邻节点加入队列, 同时增加depth步数
            if (current_node->left != nullptr)
            {
                que.emplace(current_node->left, depth + 1);
            }

            if (current_node->right != nullptr)
            {
                que.emplace(current_node->right, depth + 1);
            }
        }
        return 0;
    }
};
// @lc code=end


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
        vector<int> path;

        if (root == NULL)
        {
            return result;
        }

        traversal(root, path, result);
        return result;
    }

private:
    // 递归
    // 1. 递归函数函数参数以及返回值
    // 要传入根节点，记录每一条路径的path，和存放结果集的result，这里递归不需要返回值，代码如下：
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result)
     {
        path.push_back(cur->val);
        // 这才到了叶子节点
        // 2. 确定递归终止条件
        if (cur->left == NULL && cur->right == NULL)
         {
            string sPath;

            for (int i = 0; i < path.size() - 1; i++)   // 将path里记录的路径转为string格式
           {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);      // 记录最后一个节点（叶子节点）
            result.push_back(sPath);                        // 收集一个路径
            return;
        }

        // 3. 确定单层递归逻辑
        if (cur->left) 
        {
            traversal(cur->left, path, result);
            path.pop_back(); // 回溯
        }

        if (cur->right) 
        {
            traversal(cur->right, path, result);
            path.pop_back(); // 回溯
        }

    }


};
// @lc code=end


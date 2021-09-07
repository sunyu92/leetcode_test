/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        dfs(root, targetSum);
        return ret;   
    }

    void dfs ( TreeNode* root, int targetSum )
    {

        if (root == nullptr) 
        {
            std::cout << "dfs------------------root == nullptr" << std::endl;
            return;
        }
        else
        {
            std::cout << "dfs ------------------root_value=  " << root->val  << std::endl;
        }
        

        std::cout << "targetSum= " << targetSum << std::endl;

        path.emplace_back(root->val);
        targetSum -= root->val;
        if (root->left ==nullptr && root->right == nullptr && targetSum == 0 )
        {
            std::cout << "find it " << std::endl;
            ret.emplace_back(path);
        }

        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        std::cout << "pop_back()" << std::endl;
        path.pop_back();
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
    
public:
    vector<vector<int>>res;

    vector<vector<int>> combine(int n, int k)
    {
        if (k <= 0 || n <= 0) 
        {
            return res;
        }
        vector<int> path;
        backtrack(n, k, 1, path);
        return res;
    }

    void backtrack(int n, int k, int depth, vector<int>& path)
    {
        // 到达树的底部
        if (k == path.size()) 
        {
            res.push_back(path);
            return;
        }
        // 注意 i 从 start 开始递增
        for (int i = depth; i <= n; i++)
        {
            // 做选择
            path.push_back(i);
            backtrack(n, k, i + 1, path);
            // 撤销选择
            path.pop_back();
        }
    }
};
// @lc code=end


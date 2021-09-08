/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        backtrace( nums, res, 0 );
        return res;
    }

    void backtrace( vector<int>&  nums, vector<vector<int>>& res, int depth)
    {
        if ( depth == nums.size() -1 )      // // 所有数都填完了
        {
            res.emplace_back(nums);
            return;
        }

        for ( int i = depth; i < nums.size(); i++ )
        {
            swap( nums[i], nums[depth] );            // 修改当前节点状态
            backtrace( nums, res, depth + 1 );      // 继续递归填写下一个数
            swap( nums[i], nums[depth] );           // 撤销操作，回改当前节点状态
        }
    }
    
};
// @lc code=end


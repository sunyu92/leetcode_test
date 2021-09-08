/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack( nums, 0, path );
        return res;
    }

    void backtrack( vector<int>& nums, int depth, vector<int>& path )
    {
        res.emplace_back( path );

        for ( int i = depth; i < nums.size(); i++ )
        {
            path.push_back( nums[i] );
            backtrack( nums, i + 1, path );
            path.pop_back();
        }
    }
};
// @lc code=end


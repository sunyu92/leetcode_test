/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k)
     {
        if ( k <= 0 || n <= 0 )
        {
            return res;
        }

        vector<int> path;
        backtrace( n, k, 1, path );
        return res;
    }

    void backtrace( int n, int k, int start, vector<int>& path )
    {
        if ( k == path.size() )
        {
            
        }
    }

};
// @lc code=end


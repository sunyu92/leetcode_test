/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n)
     {
        result.clear();
        vector<string> board(n, string('.'));
        backtracing(n, 0, board);

    }

    // backtracing
    void backtraring( int n, int row, vector<string>& board )
    {
        if ( row == n )
        {
            result.emplace_back(board);
            return;
        }

        for ( int col = 0; col < n; col++)
        {
            if ( isValid( row, col, board, n ) )
            {
                board[row][col] = 'Q';
                backtracing( n, row + 1, board );
                board[row][col] = '.';
            }
        }
    }

    // isValid
    bool isValid( int row, int col, vector<string>& board, int n )
    {
        int count = 0;

        // 检查列
        for ( int i = 0; i < row )
    }

};
// @lc code=end


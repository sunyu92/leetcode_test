/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution 
{
private:
    vector<vector<string>> result;

public:
    vector<vector<string>> solveNQueens(int n)
     {
        result.clear();
        vector<string> board(n, string(n, '.'));
        backtracing(n, 0, board);
        return result;
    }

    // backtracing
    // n 为输入的棋盘大小
    // row 是当前递归到***的第几行了
    void backtracing( int n, int row, vector<string>& board )
    {
        if ( row == n )
        {
            result.emplace_back(board);
            return;
        }

        for ( int col = 0; col < n; col++)
        {
            if ( isValid( row, col, board, n ) ) // 验证合法就可以放
            {
                board[row][col] = 'Q';      // 放置皇后
                backtracing( n, row + 1, board );
                board[row][col] = '.';      // 回溯，撤销皇后
            }
        }
    }

    // isValid
    bool isValid( int row, int col, vector<string>& board, int n )
    {
        int count = 0;

        // 检查列
        for ( int i = 0; i < row; i++ )  // 这是一个剪枝
        {
            if ( board[i][col] == 'Q' )
            {
                return false;
            }
        }

        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) 
        {
            if ( board[i][j] == 'Q' )
            {
                return false;
            }
        }

        // 检查 135度角是否有皇后
        for ( int i = row -1,  j = col + 1; i >= 0 && j < n; i--, j++  )
        {
            if ( board[i][j] == 'Q' )
            {
                return false;
            }
        }

        return true;

    }

};
// @lc code=end


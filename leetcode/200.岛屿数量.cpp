/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */


// @lc code=start
class Solution {
public:
    int count = 0;
    int numIslands(vector<vector<char>>& grid) {
        for (int i =0; i < grid.size(); i++)
        {
            for (int j = 0; j <  grid[0].size(); j++ )
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        if(!isArea(grid, r, c))
        {
            return;
        }

        if ( grid[r][c] != '1' )
        {
            return;
        }

        grid[r][c] = 2;

        dfs( grid, r-1, c );
        dfs( grid, r+1, c);
        dfs( grid, r, c-1);
        dfs(grid, r, c+1);
    }
    
    bool isArea ( vector<vector<char>>& grid, int r, int c )
    {
        return ( 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size() );
    } 

};
// @lc code=end


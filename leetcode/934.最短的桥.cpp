/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
// 解题思路
// 首先随机搜索，找到一个岛，然后使用DFS/BFS将这个岛的所有1变成2，并将1旁边的0都收集起来，
// 为下面的步骤做准备。随后，对每一个收集来的0进行BFS，直到找到第二个岛
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        // dfs寻找第一个岛屿,并把1全部赋值为2
        bool find = false;

        for (int i = 0; i < m; ++i)
        {
            if (find)
            {
                break;
            }
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    find = true;
                    break;
                }
            }
        }

        // bfs寻找第二个岛屿,并把过程中经过的0赋值为2
        // 寻找第二个
        int x, y;
        int depth = 0;
        while (!points.empty())
        {
            depth++;
            int n_points = points.size();
            while (n_points--) 
            {
                auto [r, c] = points.front();
                points.pop();

                // 周围四个方向搜索
                for (int k = 0; k < 4; ++k)
                {
                    x = r + direction[k], y = c + direction[k+1];
                    // 
                    if (x >= 0 && y >= 0 && x < m && y < n) 
                    {
                        // 如果是2的话，则继续搜索
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }

                        // 找到答案，返回距离
                        if (grid[x][y] == 1)
                        {
                            return depth;
                        }
                        // 找到，加入，并置为2
                        points.emplace(x, y);
                        grid[x][y] = 2; 
                    }
                } // end for loop
            }
        }
        return 0;
    }

    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n, int i, int j)
    {
        //先考察方向问题，如果越界，或者搜索到已探索的，就返回
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
        {
            return;
        }

        //再考虑别的推出方式，如果是未探索的海洋，则将1旁边的0都收集起来
        if (grid[i][j] == 0)
        {
            points.emplace(i,j);
            return;
        }

        grid[i][j] = 2;     // 如果找到，则开始拓展
        dfs(points, grid, m, n, i - 1, j);
        dfs(points, grid, m, n, i + 1, j);
        dfs(points, grid, m, n, i, j - 1);
        dfs(points, grid, m, n, i, j + 1);
    }
};
// @lc code=end


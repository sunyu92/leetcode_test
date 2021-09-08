/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty())
        {
            return false;
        }

        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtrack(i, j, board, word, find, visited, 0);
            }
        }
        return find;
    }

    void backtrack(int i, int j, vector<vector<char>>& board, string& word, bool& find, vector<vector<bool>>& visited, int wordIndex)
    {
        // 检查是否出边界
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
         {
            return;
        }

        // 走到已经搜索过的位置，返回 || 找到答案，返回 ||当前位的字母不相等，此路不通，返回 
        if (visited[i][j] || find || board[i][j] != word[wordIndex]) 
        {
            return;
        }

        // 找到并返回 true 结果， 成功搜索到单词末尾，返回true
        if (wordIndex == word.size() - 1)
        {
            find = true;
            return;
        }

        // 标记
        visited[i][j] = true;   // 修改当前节点状态
        // // 递归子节点
        backtrack(i - 1, j, board, word, find, visited, wordIndex + 1);
        backtrack(i + 1, j, board, word, find, visited, wordIndex + 1);
        backtrack(i, j - 1, board, word, find, visited, wordIndex + 1);
        backtrack(i, j + 1, board, word, find, visited, wordIndex + 1);
        visited[i][j] = false;      // 回改当前节点状态
    }
};
// @lc code=end


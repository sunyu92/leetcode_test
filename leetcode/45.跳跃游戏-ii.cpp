/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    vector<int> memo;
    // 主函数
    int jump(vector<int>& nums) {
        int n = nums.size();
        // 备忘录都初始化为 n，相当于 INT_MAX
        // 因为从 0 调到 n - 1 最多 n - 1 步
        memo = vector<int>(n, n);
        return dp(nums, 0);
    }

    int dp(vector<int>& nums, int p) {
        int n = nums.size();
        // base case
        if (p >= n - 1) {
            return 0;
        }
        // ⼦问题已经计算过
        if (memo[p] != n) {
            return memo[p];
        }
        int steps = nums[p];
        // 你可以选择跳 1 步，2 步...
        for (int i = 1; i <= steps; i++) {
            // 穷举每⼀个选择
            // 计算每⼀个⼦问题的结果
            int subProblem = dp(nums, p + i);
            // 取其中最⼩的作为最终结果
            memo[p] = min(memo[p], subProblem + 1);
        }
        return memo[p];
    }
};
// @lc code=end


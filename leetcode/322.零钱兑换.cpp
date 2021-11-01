/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 数组大小为 amount + 1,初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i= 0; i < dp.size(); i++){
            // 内层 for 在求所有子问题 + 1 的最小值
            for (const int & coin : coins){
                // 子问题无解,跳过
                if (i - coin < 0){
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end


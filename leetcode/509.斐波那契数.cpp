/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int N) {
    if (N==0)return 0;
    if (N==1)return 1;
    if (N==2)return 1;

    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 2] + dp[i - 1];
    return dp[N];
}

};
// @lc code=end


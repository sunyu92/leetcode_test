/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution
 {
public:
    bool canPartition(vector<int>& nums)
     {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2, n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 0; j <= target; ++j)
             {
                if (j < nums[i-1])
                 {
                    dp[i][j] = dp[i-1][j];
                } 
              else
              {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
               }
            }
        }
        return dp[n][target];
        }
    };
// @lc code=end


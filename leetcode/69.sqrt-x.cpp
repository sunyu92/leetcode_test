/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long a = x;
        while (a * a > x){
            a = (a + x/a) /2;
        }
        return a;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
         if (s.empty() || s.size() < k ) return 0;
        if (k <=1) return s.size();

        unordered_map<char, int> m;
        for (char c:s)
            m[c] ++;

        int i = 0;
        while (i < s.size() && m[s[i]] >= k)
            ++ i;
        if(i == s.size()) return s.size();

        int left = longestSubstring(s.substr(0,i),k);
        while(i<s.size() && m[s[i]] < k)
            ++i;
        int right = longestSubstring(s.substr(i),k);

        return max(left,right);
    }

};
// @lc code=end


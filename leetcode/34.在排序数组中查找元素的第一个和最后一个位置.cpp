/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1; // 这里需要减1位
        if (lower == nums.size() || nums[lower] != target) {
            return vector<int>{-1, -1};
        }
        return vector<int>{lower, upper};
    }

    // 辅函数
    int lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } 
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    // 辅函数
    int upper_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size(), mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid;
            } 
            else {
                l = mid + 1;
            }
        }
        return l;
    }

};
// @lc code=end


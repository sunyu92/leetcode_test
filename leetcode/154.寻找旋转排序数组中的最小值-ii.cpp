/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                // 中间值 < 右边界值，则旋转点在中间值左侧，包含自身
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                // 中间值 > 右边界值，则旋转点在中间值右侧
                left = mid + 1;
            }
            // 不确定旋转点方向，分情况进行left++或者right--
            else --right;
        }
        // right位置就是旋转点
        return nums[right];
    }
};
// @lc code=end


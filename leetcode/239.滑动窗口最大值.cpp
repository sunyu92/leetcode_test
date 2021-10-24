/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int>q; //双端队列
            vector<int>res;
            for(int i = 0; i < nums.size(); i++){
                while(q.size() &&  i - k + 1 > q.front())  q.pop_front(); //判断是否在滑动窗口范围内
                while(q.size() && nums[i] >= nums[q.back()]) q.pop_back();//维护单调递减队列
                q.push_back(i); //将当前元素插入队列
                if(i >= k - 1)  res.push_back(nums[q.front()]); //滑动窗口的元素达到了k个，才可以将其加入答案数组中
            }
            return res;
    }
};
// @lc code=end


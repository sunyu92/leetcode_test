/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL)    return head;
        Quick_Sort(head, NULL);
        return head;    
    }
    
    void Quick_Sort(ListNode* head, ListNode* end)
    {
        if (head != end && head->next != end)
        {
            ListNode* ptr = head;
            while(ptr->next != end) ptr = ptr->next; // 取链表最后一个元素作为主元
            int pivot = ptr->val;
            
            ListNode* p1 = head;
            ListNode* p2 = head;
            
            while(p2->next != end)
            {
                if(p2->val < pivot)
                {
                    int temp = p2->val;
                    p2->val = p1->val;
                    p1->val = temp;
                    p1 = p1->next;
                }
                p2 = p2->next;
            }
            p2->val = p1->val;
            p1->val = pivot;
            Quick_Sort(head, p1); // 此时 p1 指向 pivot，前一半链表头为 head，尾为 p1
            Quick_Sort(p1->next, end); // 后一半链表头为 p1->next，尾为 end
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 特殊条件 但长度小于2 
		if(lists.size() == 0){
			return NULL;
		}
		if(lists.size() == 1){
			return lists[0];
		}
        ListNode* temp;
        for(int i = 0 ; i<lists.size()-1 ; i++){
            temp = mergeTwoLists(lists[i],lists[i+1]);
            lists[i+1] = temp;
        }
        return temp;
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1 == nullptr){
            return l2;
        }else if(l2 == nullptr){
            return l1;
        }else if(l1->val > l2->val){
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }else{
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
    }
};
// @lc code=end


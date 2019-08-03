/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
 
 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 
  */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        dummy->next = head;
        ListNode* end = dummy;
        ListNode* start = NULL;
        ListNode* next = NULL;
        
        while(end->next != NULL)
        {
            for(int i = 0; i < k && end != NULL; i++)  end = end->next;
            if(end == NULL) break;
            
            start = pre->next;
            next = end->next;
            end->next = NULL;
            pre->next = reverseList(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
    //原地翻转链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = NULL;
        ListNode* tmp = NULL;
        
        while(head != NULL)
        {
            tmp = head->next;
            head->next = p;
            p = head;
            head = tmp;
        }
        return p;
    }
};
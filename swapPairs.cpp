/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairsRec(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* next = head->next;
        head->next = swapPairsRec(next->next);
        next->next = head;
        
        return next;
    }

    ListNode* swapPairs(ListNode* head)
    {
        
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *temp = pre;
        
        while((temp->next != NULL) && (temp->next->next != NULL))
        {
            ListNode *start = temp->next;
            ListNode *end = temp->next->next;
            temp->next = end;
            start->next = end->next;
            end->next = start;
            temp = start;
        }
        
        return pre->next;
    }
};
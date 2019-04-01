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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* pList = new ListNode(0);
        ListNode* temp = pList;
        int carry = 0;
        while(l1 != NULL || l2 != NULL)
        {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            if(l1 != NULL)  l1 = l1->next;
            if(l2 != NULL)  l2 = l2->next;
        }
        if(carry > 0)
            temp->next = new ListNode(carry);
        
        return pList->next;
    }
};
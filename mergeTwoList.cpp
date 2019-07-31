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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        ListNode* newList = new ListNode(0);
        ListNode* last = newList;
        //ListNode* lastl1 = l1;
        //ListNode* lastl2 = l2;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val >= l2->val)
            {
                last->next = l2;
                l2 = l2->next;
                
            }
            else
            {
                last->next = l1;
                l1 = l1->next;
            }
            last = last->next;
        }
        
        last->next = (l1 == NULL) ? l2 : l1;
        
        return newList->next;
    }
};
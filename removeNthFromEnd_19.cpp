/**
删除链表的倒数第n个节点
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head;
        vector<ListNode*> headVec;
        
        while(temp != NULL)
        {
            headVec.push_back(temp);
            temp = temp->next;
        }
        
        int len = headVec.size();
        if(len-n == 0) return head->next;
        headVec[len-n-1]->next = headVec[len-n]->next;
        return head;
    }
};
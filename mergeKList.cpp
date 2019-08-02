/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 
 此问题有三种思路：
 （1）将所有数据读出放入一个新的链表或数组中，然后将其排序输出
 （2）分治算法，即将问题不断分割为小问题，直到最后只有两个有序链表需要合并
 （3）优先队列，可以利用数据构造一个优先队列
 
  */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        ListNode *head = NULL;
        vector<int> list;
        
        if(lists.size() == 0)
            return head;
        
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode *currentList = lists[i];
            while(currentList != NULL)
            {
                list.push_back(currentList->val);
                currentList = currentList->next;
            }
        }
        
        if(list.size() == 0)
            return head;
        sort(list.begin(), list.end());
        
        ListNode *temp = new ListNode(list[0]);
        head = temp;
        ListNode* rev = head;
        for(int j = 1; j < list.size(); j++)
        {
            temp = temp->next;
            //temp->val = list[j];
            temp = new ListNode(list[j]);
            head->next = temp;
            head = head->next;
        }
        
        return rev;
    }
};
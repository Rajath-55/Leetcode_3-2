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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while(head != NULL)
        {   
           if(head->next != NULL && head->val == head->next->val)
            {   ListNode* nd = head;
                while(nd != NULL && nd->val == head->val)
                    nd = nd->next;
                head = nd;
            }
            else
            {    
                tmp->next = head;
                tmp=tmp->next;
                head = head->next;
            }
        }
        tmp->next = NULL;
        return dummy->next;
    }
};
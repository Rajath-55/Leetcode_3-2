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
    ListNode* removeElements(ListNode* head, int val) {
        if(not head) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy, *curr = head;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
            }else{
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
        
       
        
    }
};
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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *node = head;
        while(node!=NULL){
            n++; node = node->next;
        }
        if(n==1) return head;
        
        int m = n/2, i=1;
        ListNode *prev = head;
        node = head->next;
        prev->next = NULL;
        while(i<m)
        {
            ListNode *nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode; i++;
        }
        
        if(n%2==1) node = node->next;
        while(node!=NULL)
        {
            if(node->val!=prev->val) return false;
            prev = prev->next; node = node->next;
        }
        
        return true;
        
    }
};
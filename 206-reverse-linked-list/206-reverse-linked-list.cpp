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
    ListNode* reverseList(ListNode* head) {
        if(not head or not head->next) return head;
        ListNode *curr = head->next, *prev = head;
        prev->next = nullptr;
        
        while(curr){
            ListNode *tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
        }
        return prev;
        
    }
};
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;
        
        while(curr and curr->next){
            ListNode *nextPair = curr->next->next;
            ListNode *secondNode = curr->next;
            
            // reverse:
            secondNode->next = curr;
            curr->next = nextPair;
            prev->next = secondNode;
            
            // update
            prev = curr;
            curr = nextPair;
        }
        return dummy->next;
    }
    
};
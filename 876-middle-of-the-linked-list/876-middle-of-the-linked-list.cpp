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
    ListNode* middleNode(ListNode* head) {
        if(not head or not head->next) return head;
        
        ListNode *slow = head, *fast = head->next;
        int count = 0;
        while(head){
            head = head->next;
            count++;
        }
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return count&1 ? slow : slow->next;
    }
};
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
    ListNode *detectCycle(ListNode *head) {
        bool hasCycle = false;
        ListNode *slow_pointer = head, *fast_pointer = head;
        while(slow_pointer and fast_pointer and fast_pointer->next){
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
            if(slow_pointer == fast_pointer){
                hasCycle = true;
                break;
            }
        }
        if(not hasCycle)
            return nullptr;
        if(slow_pointer == head) return head;
        fast_pointer = head;
        while(fast_pointer->next != slow_pointer->next){
            fast_pointer = fast_pointer->next;
            slow_pointer = slow_pointer->next;
        }
        return slow_pointer->next;
        
    }
};

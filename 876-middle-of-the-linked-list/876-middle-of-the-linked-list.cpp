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
        if(not head) return nullptr;
        ListNode *slow = head,*temp = head, *fast = head->next;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return cnt&1 ? slow : slow->next;
    }
};
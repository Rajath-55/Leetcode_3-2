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
        ListNode *middle = head, *fast = head->next;
        if(not head) return true;
        while(fast and fast->next){
            fast = fast->next->next;
            middle = middle->next;
        }
        cout<<middle->val<<"\n";
        ListNode *temp = middle->next;
        ListNode *prev = middle;
        middle->next = nullptr;
        while(temp){
            ListNode *currNext = temp->next;
            temp->next = prev;
            prev = temp;
            temp = currNext;
        }
        temp = prev;
    
        while(head and temp){
            cout<<head->val<<" "<<temp->val<<"\n";
            if(head->val != temp->val) return false;
            head = head->next;
            temp = temp->next;
        }
        return true;
    }
};
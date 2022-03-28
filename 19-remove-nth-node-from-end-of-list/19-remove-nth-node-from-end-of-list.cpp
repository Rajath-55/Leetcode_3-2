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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *prev;
        if(not head) return NULL;
        int sz = 0;
        while(temp){
            sz++;
            prev = temp;
            temp = temp->next;
        }
        if(sz == 1 and n == 1) return NULL;
        
        sz -=n;
        
        if(sz < 0) return NULL;
        cout<<sz<<"\n";
        temp = head;
        if(sz == 0){
            head = head->next;
            return head;
        }
        while(sz > 0){
            prev = temp;
            temp = temp->next;
            sz--;
        }
        if(temp)
        prev->next = temp->next;
        // free(temp);
        return head;
    }
        
};
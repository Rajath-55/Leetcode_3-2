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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* dummyHead = new ListNode();
        dummyHead->next = nullptr;
        ListNode* unsortedHead = head;
        ListNode* inserter = dummyHead;
        while(unsortedHead != nullptr){
            ListNode* temp = unsortedHead->next;
            while(inserter->next != nullptr && inserter->next->val < unsortedHead->val)
                inserter = inserter->next;
            unsortedHead->next = inserter->next;
            inserter->next = unsortedHead;
            inserter = dummyHead;
            unsortedHead = temp;
        }
        return dummyHead->next;
    }
};
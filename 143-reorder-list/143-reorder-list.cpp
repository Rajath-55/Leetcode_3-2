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
    void reorderList(ListNode* head) {
        if(not head or not head->next or not head->next->next) return;
        stack<ListNode*>st;
        ListNode *temp = head;
        int size = 0;
        while(temp){
            st.push(temp);
            temp = temp->next;
            size++;
        }
      
        temp = head;
        for(int i = 0; i < size/2; ++i){
            if(i == size/2 - 1 and size%2 == 0){
                temp = temp->next;
                break;
            }
            ListNode *toInsert = st.top();
           
            st.pop();
            ListNode *toInsertNext = temp->next;
            temp->next = toInsert;
            toInsert->next = toInsertNext;
            temp = toInsertNext;
        }
        temp->next = nullptr;
    }
};
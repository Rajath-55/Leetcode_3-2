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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>st;
        
        while(headA and headB){
            if(headA == headB) return headA;
            if(st.count(headA)) return headA;
            if(st.count(headB)) return headB;
            
            st.insert(headA);
            st.insert(headB);
            headA = headA->next;
            headB = headB->next;
        }
        while(headA){
            if(st.count(headA)) return headA;
            headA = headA->next;
        }
        while(headB){
            if(st.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
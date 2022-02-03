/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0, sizeB = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        
        while(temp1){
            sizeA++;
            temp1 = temp1->next;
        }
        while(temp2){
            sizeB++;
            temp2 = temp2->next;
        }
        int count;
        temp1 = headA;
        temp2 = headB;
        if(sizeA < sizeB){
            count = sizeB - sizeA;
            while(count--){
                temp2 = temp2->next;
            }
        }else{
            count = sizeA - sizeB;
            while(count--){
                temp1 = temp1->next;
            }
        }
        while(temp1 and temp2){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return nullptr;
    }
};
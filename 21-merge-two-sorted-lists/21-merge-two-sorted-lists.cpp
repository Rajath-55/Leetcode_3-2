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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newList = new ListNode(-101);
        ListNode *newPointer = newList;
        
        while(list1 or list2){
            if(list1 and list2){
                if(list1->val < list2->val){
                    newPointer->next = new ListNode(list1->val);
                    newPointer = newPointer->next;
                    list1 = list1->next;
                }else{
                    newPointer->next = new ListNode(list2->val);
                    newPointer = newPointer->next;
                    list2 = list2->next;
    
                }
        }
            else if(list1){
                    newPointer->next = new ListNode(list1->val);
                    newPointer = newPointer->next;
                    list1 = list1->next;
                }else if(list2){
                    newPointer->next = new ListNode(list2->val);
                    newPointer = newPointer->next;
                    list2 = list2->next;
                }
        }
        return newList->next;
        
            
        
    }
};
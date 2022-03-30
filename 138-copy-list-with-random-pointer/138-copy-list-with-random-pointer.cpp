/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node*> addresses;
        
        Node *curr = head, *prev = nullptr, *copied = nullptr;
        
        while(curr){
            Node *newNode = new Node(curr->val);
            addresses[curr] = newNode;
            curr = curr->next; 
        }
        Node *ans = addresses[head];
        Node *newHead = ans;
        curr = head;
        
        while(curr){
            if(curr->next){
                ans->next = addresses[curr->next];
            }
            if(curr->random){
                ans->random = addresses[curr->random];
            }
            curr = curr->next;
            ans = ans->next;
        }
        
        
        return newHead;
        
        
    }
};
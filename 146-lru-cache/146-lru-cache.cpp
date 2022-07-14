struct Node{
    int data, key;
    Node *prev, *next;
    Node(){
        data = key = 0;
        prev = next = nullptr;
    }
};


class LRUCache {
public:
    Node *head, *tail;
    unordered_map<int, Node*>mp;
    int capacity;
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    void moveFront(Node *node){
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    void remove(Node *node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
     
    
    int get(int key) {
        if(mp.count(key)){
            remove(mp[key]);
            moveFront(mp[key]);
            return mp[key]->data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto ele = mp[key];
            ele->data = value;
            remove(ele);
            moveFront(ele);
            return;
        }
        if(mp.size() == capacity){
            Node *rem = tail->prev;
            remove(rem);
            mp.erase(rem->key);
            delete rem;
        }
        Node *ele = new Node();
        ele->key = key;
        ele->data = value;
        mp[key] = ele;
        moveFront(ele);
        return;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
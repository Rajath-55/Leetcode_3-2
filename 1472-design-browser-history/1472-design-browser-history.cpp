struct Node{
    string site;
    Node* next, *prev;
    Node(string site){
        this->site = site;
        prev = next = nullptr;
    }
    Node(string site, Node *prev, Node *next){
        this->site = site;
        this->prev = prev;
        this->next = next;
    }

};


class BrowserHistory {
public:
    Node *base;
    BrowserHistory(string homepage) {
        base = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        base->next = temp;
        temp->prev = base;
        base = base->next;
    }
    
    string back(int steps) {
        while(base->prev and steps--){
            base = base->prev;
        }
        
        return base->site;
        
    }
    
    string forward(int steps) {
        while(base->next and steps--){
            base = base->next;
        }
        return base->site;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
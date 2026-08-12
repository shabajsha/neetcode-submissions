class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
    };

    unordered_map<int, Node*> mp;
    int size;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;

        prev->next = nxt;
        nxt -> prev = prev;
    }

    void addStart(Node* cur){
        Node* nxt = left->next;
        left->next = cur;
        cur->next = nxt;
        nxt->prev = cur;
        cur->prev = left;
        return;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(mp.count(key) == 0){
            return -1;
        }
        Node* cur = mp[key];
        remove(cur);
        addStart(cur);
        return cur->val; 
    }
    
    void put(int key, int value) {
        if(mp.count(key) == 0){
            Node* cur = new Node(key,value);
            mp[key] = cur;
            addStart(cur);
        }
        else{
            Node* cur = mp[key];
            remove(cur);
            cur->val = value;
            addStart(cur);
        }
        if(mp.size() > size){
            Node* lru = right->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        return;
    }
};

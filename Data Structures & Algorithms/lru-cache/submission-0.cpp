struct Node{
    int key,value;
    Node* prev;
    Node* next;

    Node() : key(0),value(0),prev(nullptr),next(nullptr){};
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

struct List{
    int size;
    Node *head;
    Node *tail;

    List(){
        head = new Node();
        tail = new Node();
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        head->next=node;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        size++;
    }

    void removeNode(Node *delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LRUCache {
public:

    unordered_map<int,Node*> mp;
    List l;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *node = mp[key];
            l.removeNode(node);
            l.addFront(node);
            return mp[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
        Node* node = new Node(key,value);
        if(l.size>=cap){
            mp.erase(l.tail->prev->key);
            l.removeNode(l.tail->prev);
            l.addFront(node);
            mp[key]=node;
        } else {
            l.addFront(node);
            mp[key]=node;
        }
        } else {
            Node* curr = mp[key];
            l.removeNode(curr);
            l.addFront(curr);
            curr->value=value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
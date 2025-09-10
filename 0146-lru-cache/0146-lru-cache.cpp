class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    Node * head = new Node(-1, -1);
    Node * tail = new Node(-1, -1);

    int cap;
    unordered_map < int, Node * > mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addNode(Node * newnode) {
        Node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
  }

  void deleteNode(Node * delnode) {
    Node * delprev = delnode -> prev;
    Node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node* node=mpp[key];
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            addNode(node);
        }
        else{
            if(mpp.size() == cap){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            addNode(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
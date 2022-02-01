// Time Complexity :-
//  GET - O(1),  PUT - O(1)
// Space Complexity - O(n)

class DLL {
public:
    int key, value;
    DLL *next, *prev;
    DLL(int x, int y) {
        key = x;
        value = y;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
    DLL *front = new DLL(-1, -1);
    DLL *back  = new DLL(-1, -1);
    unordered_map<int, DLL*> mp;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        
        front->next = back;
        back->prev = front;
    }
    
    void deleteNode(DLL* tmp) {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        
        delete tmp;
    }
    
    void addNode(DLL* tmp) {
        front->next->prev = tmp;
        tmp->next = front->next;
        tmp->prev = front;
        front->next = tmp;
    }

    int get(int key) {
        // Key not found
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        
        // Key found
        else {
            int ans = mp[key]->value;
            
            // Delete prev Node
            deleteNode(mp[key]);
            
            // Insert new Node
            DLL* newNode = new DLL(key, ans);
            addNode(newNode);
            
            mp[key] = newNode;
            
            return ans;
        }
    }
    
    void put(int key, int value) {
        DLL *tmp = new DLL(key, value);
        
        // Key not present
        if(mp.find(key) == mp.end()) {
            
            // Cache is full
            if(mp.size() == cap) {
                // Delete last Node
                int num = back->prev->key;
                deleteNode(back->prev);
                mp.erase(num);
            }
        }
        
        // Key present
        else {
            // Delete prev Node
            deleteNode(mp[key]);
        }
        
        addNode(tmp);
        mp[key] = tmp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
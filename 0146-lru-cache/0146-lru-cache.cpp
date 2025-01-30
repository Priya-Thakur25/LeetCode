class DLL {
public:
    int first, second;
    DLL* prev;
    DLL* next;

    DLL() {
        first = -1;
        second = -1;
        prev = NULL;
        next = NULL;
    }

    DLL(int first, int second) {
        this->first = first;
        this->second = second;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    DLL* head = new DLL();
    DLL* tail = new DLL();
    unordered_map<int, DLL*> mapping;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(DLL* &node) {
        DLL* temp1 = node->prev;
        DLL* temp2 = node->next;

        temp1->next = temp2;
        temp2->prev = temp1;
    }

    void insertAfterHead(DLL* &node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    int get(int key) {
        if (mapping.find(key) == mapping.end()) {
            return -1;
        }

        DLL* newnode = mapping[key];
        deleteNode(newnode);
        insertAfterHead(newnode);
        return newnode->second;
    }

    void put(int key, int value) {
        //updation
        if (mapping.find(key) != mapping.end()) {
            DLL* node = mapping[key];
            node->second = value;
            deleteNode(node);
            insertAfterHead(node);
        } else {
            if (capacity > mapping.size()){
                DLL* node = new DLL(key, value);
                mapping.insert({key, node});
                insertAfterHead(node);
            }
            else if(capacity == mapping.size()){
                DLL *node = tail->prev;
                mapping.erase(node->first);
                deleteNode(node);
                DLL *tempnode = new DLL(key,value);
                insertAfterHead(tempnode);
                mapping.insert({key,tempnode});
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
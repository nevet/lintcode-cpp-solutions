typedef pair<int, int> kv;

struct CacheNode {
    kv val;
    CacheNode *next, *prev;
    CacheNode() : next(NULL), prev(NULL) {}
    CacheNode(int key, int value) : val(kv(key, value)), next(NULL), prev(NULL) {}
};

class LRUCache{
private:
    int cap, cur;
    map<int, CacheNode*> mapper;
    CacheNode *head, *tail;
    
    void append(CacheNode *cur) {
        if (!cur) return;
        
        tail->prev->next = cur;
        cur->prev = tail->prev;
        cur->next = tail;
        tail->prev = cur;
    }
    
    void isolate(CacheNode *cur) {
        if (!cur) return;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    
    void update(CacheNode *cur) {
        isolate(cur);
        append(cur);
    }
    
    void print() {
        CacheNode *p = head;
        while (p != tail) {
            fprintf(stderr, "%d ", p->val.first);
            p = p->next;
        }
        fprintf(stderr, "|");
    }
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        cap = capacity;
        cur = 0;
        mapper.clear();
        head = new CacheNode;
        tail = new CacheNode;
        head->next = tail;
        tail->prev = head;
    }
    
    // @return an integer
    int get(int key) {
        if (key == 107) print();
        
        if (mapper[key] != NULL) {
            update(mapper[key]);
            fprintf(stderr, "%d %d|", key, mapper[key]->val.second);
            return mapper[key]->val.second;
        } else return -1;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        if (mapper[key] != NULL) {
            update(mapper[key]);
            mapper[key]->val.second = value;
            return;
        }
        
        if (cur + 1 > cap) {
            mapper[head->next->val.first] = NULL;
            head->next->val = kv(key, value);
            mapper[key] = head->next;
            update(head->next);
        } else {
            CacheNode *newNode = new CacheNode(key, value);
            mapper[key] = newNode;
            append(newNode);
            cur ++;
        }
    }
};
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */ 
    int hash(int x, int cap) {
        return (x % cap + cap) % cap;
    }
    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int cap = hashTable.size();
        vector<ListNode*> newHashTable(cap * 2);
        map<int, ListNode*> tailMapper;
        
        for (int i = 0; i < cap; i ++) {
            if (hashTable[i] != NULL) {
                ListNode *cur = hashTable[i];
                while (cur) {
                    int code = hash(cur->val, cap * 2);
                    ListNode *newNode = new ListNode(cur->val);
                    if (newHashTable[code]) {
                        tailMapper[code]->next = newNode;
                    } else {
                        newHashTable[code] = newNode;
                    }
                    
                    tailMapper[code] = newNode;
                    cur = cur->next;
                }
            }
        }
        
        return newHashTable;
    }
};

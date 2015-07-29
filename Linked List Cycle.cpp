// 2 wa
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
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        ListNode* t, *h;
        
        t = h = head;
        
        while (t && h) {
            h = h->next;
            
            if (h) {
                h = h->next;
            } else break;
            
            t = t->next;
            
            if (t == h) return true;
        }
        
        return false;
    }
};




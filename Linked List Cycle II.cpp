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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        
        ListNode *p1, *p2;
        p1 = p2 = head;
        
        while (p2->next) {
            p2 = p2->next;
            if (p2->next) {
                p1 = p1->next;
                p2 = p2->next;
            }
            
            if (p1 == p2) break;
        }
        
        if (!p2->next) return NULL;
        
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};



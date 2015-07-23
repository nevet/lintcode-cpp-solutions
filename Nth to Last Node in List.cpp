// ohko
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode* a, *b;
        
        a = b = head;
        
        while (n --) {
            b = b->next;
        }
        
        while (b) {
            a = a->next;
            b = b->next;
        }
        
        return a;
    }
};




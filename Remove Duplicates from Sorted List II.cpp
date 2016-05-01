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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        
        ListNode *prev, *cur, *next, *newHead;
        prev = new ListNode;
        prev->next = head;
        cur = head;
        next = cur->next;
        head = prev;
        
        bool first = true;
        while (next) {
            while (next && cur->val != next->val) {
                prev = cur;
                if (first && prev != head) { newHead = prev; first = false; }
                cur = next;
                next = next->next;
            }
            
            if (!next) break;
            
            while (next && cur->val == next->val) {
                next = next->next;
            }
            
            prev->next = next;
            cur = next;
            if (next) next = next->next;
            fprintf(stderr, "%d ", next ? next->val : -1);
            if (first && prev != head) { newHead = prev; first = false; }
        }
        
        if (prev == head) newHead = NULL;
        
        // ListNode *p = newHead;
        // while (p) {
        //     fprintf(stderr, "%d ", p ? p->val : -1);
        //     p = p->next;
        // }
        
        return newHead;
    }
};
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sentinal = new ListNode(-2147483648);
        sentinal->next = head;
        
        ListNode *p, *q;
        p = sentinal;
        
        while (p) {
            q = p->next;
            while (q && q->val >= p->val) {
                p = q;
                q = q->next;
            }
            
            if (q) {
                ListNode *s, *t;
                s = sentinal; t = s->next;
                
                while (t->val < q->val) {
                    s = t;
                    t = t->next;
                }
                
                p->next = q->next;
                s->next = q;
                q->next = t;
            } else break;
        }
        
        return sentinal->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        
        ListNode *p = head;
        int i = 0;
        
        while (p != NULL && i < k) {
            p = p->next;
            i ++;
        }
        
        if (p == NULL) {
            k %= i;
            p = head;
            i = 0;
            
            while (p != NULL && i < k) {
                p = p->next;
                i ++;
            }
        }
        
        ListNode *q = head;
        while (p->next != NULL) { p = p->next; q = q->next; }
        
        p->next = head;
        head = q->next;
        q->next = NULL;
        
        return head;
    }
};
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
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *p = head;
        ListNode *q = NULL;
        
        while (p) {
            while (p && p->val == val) {
                p = p->next;
            }
            
            if (q) {
                q->next = p;
            } else {
                head = p;
            }
            
            if (p) {
                q = p;
                p = p->next;
            }
        }
        
        return head;
    }
};
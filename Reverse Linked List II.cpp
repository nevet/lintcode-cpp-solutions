/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverse(ListNode *left, ListNode *right) {
        ListNode *prev, *cur;
        prev = left; cur = left->next;
        ListNode *temp;
        while (cur != right) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            fprintf(stderr, "in reverse: prev = %d, cur = %d | ", prev->val, cur->val);
        }
        
        right->next = prev;
        return right;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (n == m) return head;
        
        ListNode *prev, *left, *right;
        prev = new ListNode;
        left = right = head;
        prev->next = left;
        
        for (int i = 0; i < n - m; i ++) right = right->next;
        for (int i = 1; i < m; i ++) {
            prev = left;
            left = left->next;
            right = right->next;
        }
        
        fprintf(stderr, "prev = %d, left = %d, right = %d", prev->val, left->val, right->val);
        
        ListNode *temp = right->next;
        prev->next = reverse(left, right);
        left->next = temp;
        
        return m == 1 ? prev->next : head;
    }
};

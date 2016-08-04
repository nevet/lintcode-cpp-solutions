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
     * @return a boolean
     */
    void print(ListNode *head) {
        for (ListNode *p = head; p; p = p->next) fprintf(stderr, "%d|", p->val);
    }
    
    ListNode* reverse(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *next = head->next;
        if (!next) return head;
        ListNode *newHead = reverse(next);
        next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        
        ListNode *p, *q;
        p = q = head;
        while (q->next) {
            q = q->next;
            if (q->next) {
                q = q->next;
                p = p->next;
            }
        }
        print(p->next);
        p->next = q = reverse(p->next);
        print(head);
        p = head;
        while (q) {
            if (p->val != q->val) return false;
            p = p->next; q = q->next;
        }
        
        return true;
    }
};
// 1->2->2->1
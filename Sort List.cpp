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
    void print(ListNode *s) {
        if (s) fprintf(stderr, "%d|", s->val); else fprintf(stderr, "nil|");
    }

    void printList(ListNode *s) {
        ListNode *cur = s;
        while (cur) {
            fprintf(stderr, "%d->", cur->val);
            cur = cur->next;
        }
        print(NULL);
    }

    ListNode* merge(ListNode *s1, ListNode *s2) {
        if (s1 == NULL) return s2;
        if (s2 == NULL) return s1;
        
        if (s1->val < s2->val) {
            s1->next = merge(s1->next, s2);
            return s1;
        }
        
        s2->next = merge(s1, s2->next);
        return s2;
    }
    
    ListNode* sort(ListNode *head) {
        if (!head || !head->next) return head;
        // print(head);
        
        ListNode *p, *q;
        p = q = head;
        
        while (q->next) {
            q = q->next;
            if (q->next) {
                p = p->next;
                q = q->next;
            }
        }
        
        q = sort(p->next);
        p->next = NULL;
        p = sort(head);
        
        // printList(p); printList(q);
        return merge(p, q);
    }
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        return sort(head);
    }
};



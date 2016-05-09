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
     * @return: void
     */
    
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
    
    ListNode *reverse(ListNode *s) {
        ListNode *cur = s;
        ListNode *prev, *temp;
        prev = temp = NULL;
        
        while (cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }
    
    ListNode *combine(ListNode *p1, ListNode *p2) {
        ListNode *head, *cur;
        head = cur = p1; p1 = p1->next;
        int c = 0;
        
        while (p1 || p2) {
            if (c) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }
            
            cur = cur->next;
            c ^= 1;
        }
        
        return head;
    }
    
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *p1, *p2;
        p1 = p2 = head;
        
        while (p2) {
            // fprintf(stderr, "%d|", p2->val);
            p2 = p2->next;
            if (p2 && p2->next) {
                p1 = p1->next;
                p2 = p2->next;
            } else break;
        }
        
        print(p1); print(p2);
        
        p2 = reverse(p1->next);
        p1->next = NULL; p1 = head;
        
        printList(p2); printList(p1);
        
        head = combine(p1, p2);;
    }
};

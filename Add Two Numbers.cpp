// 1 wa
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *a, *b, *c;
        
        a = l1;
        b = l2;
        
        while (a && b) {
            a->val += b->val;
            c = a;
            a = a->next;
            b = b->next;
        }
        
        if (b) {
            c->next = b;
        }
        
        a = l1;
        
        while (a) {
            if (a->next) {
                a->next->val += a->val / 10;
            } else
            if (a->val / 10) {
                a->next = new ListNode(a->val / 10);
            }
            
            a->val %= 10;
            
            a = a->next;
        }
        
        return l1;
    }
};

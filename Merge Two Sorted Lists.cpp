// 4 wa
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode* a, *b, *head, *temp;
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        if (l1->val < l2->val) {
            a = l1; b = l2;
        } else {
            a = l2; b = l1;
        }
        
        head = a;
        
        while (a && b) {
            while (a && (!b || a->val <= b->val)) {
                temp = a;
                a = a->next;
            }
            
            temp->next = b;
            
            while (b && (!a || b->val <= a->val)) {
                temp = b;
                b = b->next;
            }
            
            temp->next = a;
        }
        
        return head;
    }
};

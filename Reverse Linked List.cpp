// ohko
/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp;
        
        while (cur) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }
};


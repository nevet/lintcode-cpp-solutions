// 1 wa
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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        ListNode* cur = NULL, *it = head, *temp;
        
        while (it && it->val < x) {
            cur = it;
            it = it->next;
        }
        
        while (it) {
            if (it->val >= x) {
                temp = it;
                it = it->next;
            } else {
                temp->next = it->next;
                
                if (cur) {
                    it->next = cur->next;
                    cur = cur->next = it;
                } else {
                    it->next = head;
                    head = cur = it;
                }
                
                it = temp->next;
            }
        }
        
        return head;
    }
};




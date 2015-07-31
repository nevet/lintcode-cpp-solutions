// ohko
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        if (!node->next) {
            delete node;
            node = NULL;
            
            return;
        }
        
        node->val ^= node->next->val ^= node->val ^= node->next->val;
        
        ListNode* temp = node->next;
        node->next = node->next->next;
        temp->next = NULL;
        delete temp;
    }
};

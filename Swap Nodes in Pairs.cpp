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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        ListNode *sentinal = new ListNode();
        sentinal->next = head;
        ListNode *cur = sentinal;
        ListNode *next = head;
        
        while (next) {
            if (next->next) {
                cur->next = next->next;
                ListNode *temp = next->next->next;
                next->next->next = next;
                next->next = temp;
            }
            cur = next;
            next = next->next;
        }
        
        return sentinal->next;
    }
};
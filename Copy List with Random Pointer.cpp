/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        
        RandomListNode *cur, *temp;
        cur = head;
        
        while (cur) {
            temp = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur = cur->next->next = temp;
        }
        
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        RandomListNode *newHead = head->next;
        cur = head;
        while (cur) {
            temp = cur->next;
            if (temp) cur->next = temp->next;
            cur = temp;
        }
        
        return newHead;
    }
};
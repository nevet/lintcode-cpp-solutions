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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    void print(ListNode* a) {
        fprintf(stderr, "%d|", a ? a->val : -1);
    }
    
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        ListNode *sentinel = new ListNode;
        sentinel->next = head;
        
        ListNode *anode, *bnode, *aprev, *bprev, *cur;
        aprev = sentinel; cur = anode = bnode = head;
        bool findB = false;
        
        while (cur) {
            if (cur->val == v1 || cur->val == v2) {
                if (findB) break; else {
                    bprev = aprev;
                    bnode = anode;
                    findB = true;
                }
            }
            
            cur = cur->next;
            
            if (findB) {
                bprev = bprev->next; 
                bnode = bnode->next;
            } else {
                aprev = aprev->next; 
                anode = anode->next;
            }
        }
        
        if (!anode || !bnode) return head;
        
        aprev->next = bnode;
        ListNode *temp = anode->next == bnode ? anode : anode->next;
        anode->next = bnode->next;
        bnode->next = temp;
        if (bprev != anode) bprev->next = anode;
        
        return sentinel->next;
    }
};
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
typedef pair<int, ListNode*> inode;

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<inode> pq;
        
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i]) pq.push(inode(-lists[i]->val, lists[i]));
        }
        
        ListNode *sentinal = new ListNode();
        ListNode *head = sentinal;
        while (!pq.empty()) {
            inode u = pq.top(); pq.pop();
            head->next = u.second;
            if (u.second->next) pq.push(inode(-u.second->next->val, u.second->next));
            head = head->next;
        }
        
        return sentinal->next;
    }
};



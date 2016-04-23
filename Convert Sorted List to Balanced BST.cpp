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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    TreeNode* sort(ListNode *s, ListNode *e) {
        if (!s) return NULL;
        if (s == e) return new TreeNode(s->val);
        
        ListNode* slow, *fast;
        slow = fast = s;
        while (fast != e) {
            fast = fast->next;
            if (fast != e) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        TreeNode* root = new TreeNode(slow->val);
        if (s != slow) root->left = sort(s, slow);
        if (slow->next != e) root->right = sort(slow->next, e);
        
        return root;
    }
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        return sort(head, NULL);
    }
};



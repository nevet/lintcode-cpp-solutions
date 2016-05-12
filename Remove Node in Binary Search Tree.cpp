/**
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
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        TreeNode *cur = root;
        TreeNode *sentinel, *p;
        sentinel = new TreeNode; sentinel->left = root; p = sentinel;
        int d = 0;
        while (cur && cur->val != value) {
            p = cur;
            if (value > cur->val) { d = 1; cur = cur->right; } else
            if (value < cur->val) { d = 0; cur = cur->left; }
        }
        
        if (!cur) return root;
        
        if (!cur->right) {
            if (d == 1) {
                p->right = cur->left;
            } else {
                p->left = cur->left;
            }
        } else
        if (!cur->right->left) {
            cur->right->left = cur->left;
            if (d == 1) {
                p->right = cur->right;
            } else {
                p->left = cur->right;
            }
        } else {
            TreeNode *temp = cur->right->left;
            p = cur->right;
            while (temp->left != NULL) {
                p = temp;
                temp = temp->left;
            }
            cur->val ^= temp->val ^= cur->val ^= temp->val;
            p->left = removeNode(temp, temp->val);
        }
        
        return sentinel->left;
    }
};
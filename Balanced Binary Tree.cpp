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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    int treeSize(TreeNode *root) {
        if (!root) return 0;
        return max(treeSize(root->left), treeSize(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(treeSize(root->left) - treeSize(root->right)) <= 1;
    }
};
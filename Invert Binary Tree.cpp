// ohko
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if (root == NULL) return;
        
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = temp;
    }
};

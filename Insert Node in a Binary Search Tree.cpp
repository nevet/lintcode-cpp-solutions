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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (!root) return node;
        TreeNode* cur = root;
        
        while (true) {
            if (node->val < cur->val) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = node;
                
                    break;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = node;
                
                    break;
                }
            }
        }
        
        return root;
    }
};

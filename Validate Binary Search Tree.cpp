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
# define MIN -21474836481LL
# define MAX 21474836471LL

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValid(TreeNode *root, long long upper, long long lower) {
        if (!root) return true;
        if ((long long)root->val >= upper || (long long)root->val <= lower) return false;
        return isValid(root->left, (long long)root->val, lower) && isValid(root->right, upper, (long long)root->val);
    }
     
    bool isValidBST(TreeNode *root) {
        return isValid(root, MAX, MIN);
    }
};
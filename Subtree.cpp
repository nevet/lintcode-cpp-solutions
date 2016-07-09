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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL) return true;
        if (T1 == NULL) return false;
        
        return same(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
    
    bool same(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL || T2 == NULL) return false;
        if (T1->val == T2->val) return same(T1->left, T2->left) && same(T1->right, T2->right);
        return false;
    }
};
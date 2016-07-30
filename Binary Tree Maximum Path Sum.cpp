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
typedef pair<int, int> ii;

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    ii find(TreeNode *root) {
        if (root == NULL) return ii(-10000000, -10000000);
        
        ii left = find(root->left);
        ii right = find(root->right);
        
        int single = max(max(left.first, right.first) + root->val, root->val);
        int both = left.first + right.first + root->val;
        return ii(single, max(max(left.second, right.second), max(single, both)));
    }
    
    int maxPathSum(TreeNode *root) {
        return find(root).second;
    }
};
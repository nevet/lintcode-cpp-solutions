// need to fucking rewrite!!!

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
    TreeNode* strip(TreeNode* root) {
        if (!root || !root->left && !root->right) return root;
        
        TreeNode* last = root->right ? strip(root->right) : NULL;
        if (last) {
            if (root->left) {
                strip(root->left)->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
        } else {
            last = strip(root->left);
            root->right = root->left;
            root->left = NULL;
        }
        
        return last;
    }
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        strip(root);
    }
};

// {1,2,3,#,#,4,#,#,5,#,6}
// {98,97,#,88,#,84,#,79,87,64,#,#,#,63,69,62,#,#,#,30,#,27,59,9,#,#,#,3,#,0,#,-4,#,-16,#,-18,-7,-19,#,#,#,-23,#,-34,#,-42,#,-59,#,-63,#,-64,#,-69,#,-75,#,-81}
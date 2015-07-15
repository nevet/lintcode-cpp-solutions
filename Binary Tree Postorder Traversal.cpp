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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> list;
        
        if (root == NULL) return list;
        
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        
        list.insert(list.end(), left.begin(), left.end());
        list.insert(list.end(), right.begin(), right.end());
        list.push_back(root->val);
        
        return list;
    }
};

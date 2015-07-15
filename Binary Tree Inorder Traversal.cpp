// 1 wa
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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> list;
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> list;
        
        if (root == NULL) return list;
        
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        
        list.insert(list.end(), left.begin(), left.end());
        list.push_back(root->val);
        list.insert(list.end(), right.begin(), right.end());
        
        return list;
    }
};

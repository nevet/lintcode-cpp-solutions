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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> list;
        
        if (root == NULL) return list;
        
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        
        list.push_back(root->val);
        list.insert(list.end(), left.begin(), left.end());
        list.insert(list.end(), right.begin(), right.end());
        
        return list;
    }
};


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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int> > ans;
    
    void find(TreeNode *root, int target, vector<int> v) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (target == root->val) {
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        
        v.push_back(root->val);
        find(root->left, target - root->val, v);
        find(root->right, target - root->val, v);
        v.pop_back();
    }
    
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<int> v;
        find(root, target, v);
        
        return ans;
    }
};
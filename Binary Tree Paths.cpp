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
    void traverse(TreeNode* root, string now, vector<string>& ans) {
        if (!root) {
            return;
        }
        
        if (now != "") {
            now += "->";
        }
        
        string cur = to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(now+cur);
            return;
        }
        
        traverse(root->left, now + cur, ans);
        traverse(root->right, now + cur, ans);
    }
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) return ans;
        traverse(root, "", ans);
        return ans;
    }
};
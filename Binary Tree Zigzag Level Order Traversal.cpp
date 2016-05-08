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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        vector<stack<TreeNode*>> stacks(2);
        
        if (!root) return ans;
        
        stacks[0].push(root);
        int cur = 0;
        while (!stacks[cur].empty()) {
            vector<int> v;
            
            while (!stacks[cur].empty()) {
                TreeNode *u = stacks[cur].top(); stacks[cur].pop();
                v.push_back(u->val);
                if (cur) {
                    if (u->right) stacks[cur ^ 1].push(u->right);
                    if (u->left) stacks[cur ^ 1].push(u->left);
                } else {
                    if (u->left) stacks[cur ^ 1].push(u->left);
                    if (u->right) stacks[cur ^ 1].push(u->right);
                }
            }
            
            cur ^= 1;
            ans.push_back(v);
        }
        
        return ans;
    }
};
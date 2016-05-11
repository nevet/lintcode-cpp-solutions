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
 
 typedef pair<TreeNode*, int> ti;
 
class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        int cur = -1;
        queue<ti> q;
        
        if (!root) return ans;
        
        q.push(ti(root, 0));
        while (!q.empty()) {
            ti u = q.front(); q.pop();
            
            if (u.second > cur) {
                vector<int> v;
                ans.push_back(v);
                cur ++;
            }
            
            ans[cur].push_back(u.first->val);
            if (u.first->left) q.push(ti(u.first->left, cur + 1));
            if (u.first->right) q.push(ti(u.first->right, cur + 1));
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
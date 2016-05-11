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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<ti> q;
        vector<vector<int> > vvi;
        
        if (!root) return vvi;
        
        q.push(ti(root, 0));
        vector<int> now;
        vvi.push_back(now);
        int cur = 0;
        while (!q.empty()) {
            ti u = q.front();
            q.pop();
            
            if (u.second > cur) {
                cur ++;
                vector<int> newV;
                vvi.push_back(newV);
            }
            
            vvi[cur].push_back(u.first->val);
            
            if (u.first->left) q.push(ti(u.first->left, cur + 1));
            if (u.first->right) q.push(ti(u.first->right, cur + 1));
        }
        
        return vvi;
    }
};

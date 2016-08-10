/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
typedef pair<int, int> ii;
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    ii rob(TreeNode* root) {
        if (!root) return ii(0, 0);
        
        ii left = rob(root->left);
        ii right = rob(root->right);
        
        return ii(root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second));
    }
    
    int houseRobber3(TreeNode* root) {
        ii ans = rob(root);
        return max(ans.first, ans.second);
    }
};
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int l, int r, int &cur) {
        if (l > r) return NULL;
        
        TreeNode *node = new TreeNode(postorder[cur]);
        if (l == r) {
            cur --;
            return node;
        }
        
        int next = l;
        for (; next <= r; next ++) {
            if (inorder[next] == postorder[cur]) break;
        }
        
        cur --;
        node->right = build(inorder, postorder, next + 1, r, cur);
        node->left = build(inorder, postorder, l, next - 1, cur);
        
        return node;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int cur = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, cur);
    }
};
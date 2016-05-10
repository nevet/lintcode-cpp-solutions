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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int inl, int inr, int &pl) {
        if (inl > inr) return NULL;
        
        TreeNode *node = new TreeNode(preorder[pl]);
        pl ++;
        if (inl == inr) return node;
        
        int next;
        for (int i = inl; i <= inr; i ++) {
            if (inorder[i] == node->val) {
                next = i; break;
            }
        }
        
        node->left = build(preorder, inorder, inl, next - 1, pl);
        node->right = build(preorder, inorder, next + 1, inr, pl);
        
        return node;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int pl = 0;
        return build(preorder, inorder, 0, preorder.size() - 1, pl);
    }
};
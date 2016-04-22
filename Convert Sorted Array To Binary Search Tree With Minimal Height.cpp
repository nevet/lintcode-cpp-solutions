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
    TreeNode *sortArray(vector<int> &A, int l, int r) {
        if (l == r) return new TreeNode(A[l]);
        if (l > r) return NULL;
        
        int m = (l + r) >> 1;
        TreeNode *node = new TreeNode(A[m]);
        node->left = sortArray(A, l, m - 1);
        node->right = sortArray(A, m + 1, r);
        
        return node;
    }
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return sortArray(A, 0, A.size() - 1);
    }
};



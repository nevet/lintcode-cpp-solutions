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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return generateBST(1, n);
    }
    
    vector<TreeNode *> generateBST(int low, int high) {
        // fprintf(stderr, "%d %d|", low, high);
        vector<TreeNode *> ret;
        
        if (low > high) {
            ret.push_back(NULL);
        }
        
        if (low == high) {
            ret.push_back(new TreeNode(low));
            return ret;
        }
        
        for (int i = low; i <= high; i ++) {
            vector<TreeNode *> left = generateBST(low, i - 1);
            vector<TreeNode *> right = generateBST(i + 1, high);
            
            for (int j = 0; j < left.size(); j ++)
                for (int k = 0; k < right.size(); k ++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[j]; root->right = right[k];
                    ret.push_back(root);
                }
        }
        
        // fprintf(stderr, "size %d|", (int)ret.size());
        
        return ret;
    }
};
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        if (!root) return "#|";
        string str = to_string(root->val) + "|";
        return str + serialize(root->left) + serialize(root->right);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *travel(vector<string> tokens, int& cur) {
        TreeNode *node = new TreeNode;
        
        if (tokens[cur] != "#") {
            node->val = atoi(tokens[cur].c_str());
            cur ++;
        } else {
            cur ++;
            return NULL;
        }
        
        node->left = travel(tokens, cur);
        node->right = travel(tokens, cur);
        
        return node;
    }
    
    TreeNode *deserialize(string data) {
        stringstream sin(data);
        vector<string> tokens;
        string token;
        
        while (getline(sin, token, '|')) {
            tokens.push_back(token);
        }
        
        int cur = 0;
        return travel(tokens, cur);
    }
};

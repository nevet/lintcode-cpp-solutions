class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> ans;
    
    void generate(int left, int right, string s) {
        if (left == 0 && right == 0) {
            ans.push_back(s);
            return;
        }
        
        if (right == 0) generate(left - 1, right, s + '('); else
        if (left == 0) generate(left, right - 1, s + ')'); else {
            generate(left - 1, right, s + '(');
            if (left < right) generate(left, right - 1, s + ')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        generate(n, n, "");
        return ans;
    }
};
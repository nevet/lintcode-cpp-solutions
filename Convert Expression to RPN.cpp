class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    int getPrecedence(string opt, int bracket) {
        switch (opt[0]) {
            case '-': case '+':
                return 1 + bracket * 2;
            case '*': case '/':
                return 2 + bracket * 2;
        }
        
        return bracket * 2;
    }
    
    vector<string> ans;
    
    void convert(vector<string> &exp, int l, int r) {
        if (l > r) return;
        
        if (l == r) {
            ans.push_back(exp[l]);
            return;
        }
        
        int bracket = 0;
        int lowest = 1000000;
        int lowestPos = -1;
        for (int i = l; i <= r; i ++) {
            if (exp[i] == "(") bracket ++; else
            if (exp[i] == ")") bracket --; else
            if (exp[i][0] < '0') {
                int p = getPrecedence(exp[i], bracket);
                if (p <= lowest) {
                    lowest = p;
                    lowestPos = i;
                }
            }
        }
        
        if (bracket > 0) convert(exp, l + 1, r); else
        if (bracket < 0) convert(exp, l, r - 1); else
        if (lowestPos == -1) convert(exp, l + 1, r - 1); else {
            convert(exp, l, lowestPos - 1);
            convert(exp, lowestPos + 1, r);
            ans.push_back(exp[lowestPos]);
        }
    }
    
    vector<string> convertToRPN(vector<string> &expression) {
        convert(expression, 0, expression.size() - 1);
        return ans;
    }
};
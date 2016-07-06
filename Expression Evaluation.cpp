class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int findPrecedence(vector<string> &exp, int l, int r) {
        int brackets = 0;
        int m = 2147483647;
        int mp = -1;
        
        for (int i = l; i <= r; i ++) {
            int cur = 2147483647;
            if (exp[i] == "(") { brackets ++; continue; } else
            if (exp[i] == ")") { brackets --; continue; } else
            if (exp[i] == "+" || exp[i] == "-") cur = 1 + brackets * 2; else
            if (exp[i] == "*" || exp[i] == "/") cur = 2 + brackets * 2; else continue;
            
            if (cur <= m) {
                m = cur;
                mp = i;
            }
        }
        
        return mp;
    }
    
    int evaluate(vector<string> &exp, int l, int r) {
        int p = findPrecedence(exp, l, r);
        
        // printf("%d %d %d\n", l, r, p);
        
        if (p == -1) {
            for (int i = l; i <= r; i ++) {
                if (exp[i] != "(" && exp[i] != ")") {
                    return stoi(exp[i]);
                }
            }
            
            return 0;
        }
        
        int left = evaluate(exp, l, p - 1);
        // printf("left = %d %d %d\n", left, l, r);
        int right = evaluate(exp, p + 1, r);
        // printf("right = %d %d %d\n", right, l, r);
        
        if (exp[p] == "+") return left + right;
        if (exp[p] == "-") return left - right;
        if (exp[p] == "*") return left * right;
        if (exp[p] == "/") return left / right;
    }
    
    int evaluateExpression(vector<string> &exp) {
        if (exp.size() == 0) return 0;
        
        return evaluate(exp, 0, exp.size() - 1);
    }
};
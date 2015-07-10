// 2 wa
class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        stack<char> stk;
        
        int len = s.length();
        
        for (int i = 0; i < len; i ++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                char x = stk.top();
                
                switch (x) {
                    case '(':
                        if (s[i] != ')') return false;
                        break;
                    case '[':
                        if (s[i] != ']') return false;
                        break;
                    case '{':
                        if (s[i] != '}') return false;
                }
                
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};

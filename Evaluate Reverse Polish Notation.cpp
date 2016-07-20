class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i ++) {
            if (tokens[i] == "+") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b + a);
            } else if (tokens[i] == "-") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b - a);
            } else if (tokens[i] == "*") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b * a);
            } else if (tokens[i] == "/") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                stk.push(b / a);
            } else stk.push(stoi(tokens[i]));
        }
        
        return stk.top();
    }
};
// 4 wa
class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        stack<char> stk;
        
        int len = A.length();
        int i = 0;
        
        while (i < len) {
            while (!stk.empty() && A[i] < stk.top() && k > 0) {
                stk.pop();
                k --;
            }
            
            stk.push(A[i]);
            
            i ++;
        }
        
        string s = "";
        
        while (!stk.empty() && k > 0) {
            stk.pop();
            k --;
        }
        
        while (!stk.empty()) {
            s = stk.top() + s;
            stk.pop();
        }
        
        i = 0;
        
        while (i < s.length() && s[i] == '0') i ++;
        
        if (i == s.length()) s = ""; else {
            s = s.substr(i);
        }
        
        if (s == "") s = "0";
        
        return s;
    }
};


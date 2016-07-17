class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        stack<string> stk;
        
        int i, j, n;
        i = 0; n = path.size();
        while (i < n) {
            j = i;
            while (j < n && path[j] == '/') j ++;
            i = j;
            
            if (j < n) {
                while (j < n && path[j] != '/') j ++;
                string p = path.substr(i, j - i);
                if (p == "..") {
                    if (!stk.empty()) stk.pop();
                } else if (p != ".") {
                    stk.push(p);
                }
            }
            
            i = j;
        }
        
        string ans = "";
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        
        if (ans == "") ans = "/";
        
        return ans;
    }
};
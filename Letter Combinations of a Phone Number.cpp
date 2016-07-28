class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> ans;
    
    void gen(string &digits, vector<vector<char> > lookup, int pos, string cur) {
        if (pos == digits.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int j = 0; j < lookup[digits[pos] - '0'].size(); j ++) {
            gen(digits, lookup, pos + 1, cur + lookup[digits[pos] - '0'][j]);
        }
    }
    
    vector<string> letterCombinations(string& digits) {
        if (digits == "") return ans;
        
        vector<vector<char> > lookup(10);
        lookup[0].push_back(' ');
        
        for (int i = 2; i <= 7; i ++)
            for (int j = 0; j < 3; j ++) {
                lookup[i].push_back('a' + 3 * (i - 2) + j);
            }
        
        lookup[7].push_back('s');
        
        lookup[8].push_back('t');
        lookup[8].push_back('u');
        lookup[8].push_back('v');
        
        lookup[9].push_back('w');
        lookup[9].push_back('x');
        lookup[9].push_back('y');
        lookup[9].push_back('z');
        
        gen(digits, lookup, 0, "");
        
        return ans;
    }
};
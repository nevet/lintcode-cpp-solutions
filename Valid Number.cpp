class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isDecimal(string s) {
        if (s == "") return false;
        
        for (int i = 0; i < s.size(); i ++)
            if (s[i] < '0' || s[i] > '9') return false;
        return true;
    }
    
    bool isEmpty(string s) {
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] != ' ') return false;
        }
        
        return true;
    }
    
    bool isNumber(string& s) {
        int i = 0;
        while (s[i] == ' ') i ++;
        if (s[i] == '+' || s[i] == '-') i ++;
        
        int j = i;
        while (j < s.size() && s[j] != ' ') j++;
        
        if (j < s.size() && !isEmpty(s.substr(j, s.size() - j))) return false;
        
        s = s.substr(i, j - i);
        i = j = 0;
        fprintf(stderr, "%s|", s.c_str());
        while (j < s.size() && s[j] != 'e' && s[j] != '.' && s[j] != 'E') j ++;
        
        string first = s.substr(i, j - i);
        string second = j + 1 < s.size() ? s.substr(j + 1, s.size() - j - 1) : "";
        
        fprintf(stderr, "%s, %s|", first.c_str(), second.c_str());
        
        if (j == s.size()) return isDecimal(first);
        if (s[j] == ' ') return isNumber(first) && isEmpty(second);
        if (s[j] == 'E' || s[j] == 'e') return isDecimal(first) && isDecimal(second);
        if (s[j] == '.') {
            if (isEmpty(first)) return isDecimal(second);
            return isDecimal(first) && (isDecimal(second) || isEmpty(second));
        }
        
        return false;
    }
};
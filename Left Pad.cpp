class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        int len = originalStr.length();
        
        string ans = "";
        for (int i = 0; i < size - len; i ++) {
            ans += padChar;
        }
        
        ans += originalStr;
        
        return ans;
    }
};
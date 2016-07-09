class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        int i = length - 1;
        int spaces = 0;
        for (int i = 0; i < length; i ++) {
            if (string[i] == ' ') spaces ++;
        }
        
        // fprintf(stderr, "%s|", string);
        
        if (spaces == 0) return length;
        char extra[spaces * 2 + 1];
        memset(extra, 96, sizeof(extra));
        strcat(string, extra);
        // fprintf(stderr, "%s|", string);
        length += spaces * 2;
        int j = length - 1;
        
        while (i < j) {
            while (string[i] != ' ') {
                string[j] = string[i];
                j --; i --;
            }
            string[j] = '0'; string[j - 1] = '2'; string[j - 2] = '%';
            i --; j -= 3;
        }
        
        // fprintf(stderr, "%d|", length);
        string[length] = '\0';
        // fprintf(stderr, "%s|", string);
        
        return length;
    }
};  
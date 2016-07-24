class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int i, j;
        i = 0; j = letters.size() - 1;
        while (i < j) {
            while (i < j && letters[i] >= 'a' && letters[i] <= 'z') i ++;
            while (i < j && letters[j] >= 'A' && letters[j] <= 'Z') j --;
            if (i < j) {
                letters[i] ^= letters[j] ^= letters[i] ^= letters[j];
                i ++; j --;
            }
        }
    }
};

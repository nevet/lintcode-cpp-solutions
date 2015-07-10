// 1 wa
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int h[26];
        
        memset(h, 0, sizeof(h));
        
        int lena = A.length();
        int lenb = B.length();
        
        for (int i = 0; i < lena; i ++) {
            h[A[i] - 'A'] ++;
        }
        
        for (int j = 0; j < lenb; j ++) {
            if (!h[B[j] - 'A']) return false;
            
            h[B[j] - 'A'] --;
        }
        
        return true;
    }
};


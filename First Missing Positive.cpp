// 6 wa
class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int n = A.size();
        
        for (int i = 0; i < n; i ++) {
            A[i] --;
            
            if (A[i] < 0) A[i] = -1;
        }
        
        for (int i = 0; i < n; i ++) {
            int p = i;
            int cur = A[p];
            
            while (cur >= 0) {
                if (cur < n) {
                    p = cur;
                    cur = A[p];
                    A[p] = -2;
                } else break;
            }
        }
        
        // -1 3 1 0 8 9
        
        for (int i = 0; i < n; i ++) {
            if (A[i] != -2) return i + 1;
        }
        
        return n + 1;
    }
};

// 2 wa
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int n = A.size();
        int m = 0;
        
        for (int i = 0; i < n; i ++) {
            m = max(m, A[i] + i);
            
            if (A[i] == 0) {
                if (m <= i) return false;
            }
        }
        
        return true;
    }
};


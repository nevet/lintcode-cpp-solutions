typedef pair<int, int> ii;

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int m = 0;
        int n = A.size();
        if (n <= 1) return n;
        if (A[0] >= n - 1) return 1;
        
        int i = 1;
        for (; i <= A[0]; i ++) m = max(m, i + A[i]);
        
        int ans = 1;
        while (m < n - 1) {
            ans ++;
            
            int next = m;
            for (; i <= m; i ++) next = max(next, i + A[i]);
            
            if (next == m) return -1;
            m = next;
        }
        
        return ans + 1;
    }
};
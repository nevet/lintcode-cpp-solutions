class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long sortAndCount(vector<int>& A, int left, int len) {
        int right = left + len;
        if (right >= A.size()) return 0;
        
        int end = min(right + len, (int)A.size());
        int i = left;
        int j = right;
        int t = 0;
        vector<int> v;
        
        while (i < right && j < end) {
            while (i < right && A[i] <= A[j]) v.push_back(A[i++]);
            while (j < end && A[i] > A[j]) {
                v.push_back(A[j++]);
                t += right - i;
            }
        }
        
        while (i < right) v.push_back(A[i++]);
        while (j < end) v.push_back(A[j++]);
        
        for (i = left; i < end; i ++) A[i] = v[i - left];
        
        return t;
    }
    
    long long reversePairs(vector<int>& A) {
        int n = A.size();
        int len = 1;
        int ans = 0;
        while (len < n) {
            // printf("%d\n", len);
            for (int i = 0; i < n; i += len * 2) {
                ans += sortAndCount(A, i, len);
            }
            // for (int i = 0; i < n; i ++) printf("%d ", A[i]);
            // printf("\n");
            len <<= 1;
        }
        
        return ans;
    }
};
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long long ans = 1;
        long long f[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; i ++) f[i] = f[i - 1] * i;
        
        for (int i = n - 1; i >= 0; i --) {
            unordered_map<int, int> hash;
            int count = 0;
            long long dup = 1;
            hash[A[i]] = 1;
            for (int j = i + 1; j < n; j ++) {
                count += A[i] > A[j];
                if (hash.find(A[j]) == hash.end()) {
                    hash[A[j]] = 1;
                } else {
                    hash[A[j]] ++;
                    dup *= hash[A[j]];
                }
            }
            // printf("%d %lld\n", count, dup);
            ans += count * f[n - i - 1] / dup;
        }
        
        return ans;
    }
};
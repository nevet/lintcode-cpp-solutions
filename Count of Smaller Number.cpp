class Solution {
public:
    vector<int> justLoop(vector<int> &A, vector<int> &queries) {
        int n = A.size();
        int m = queries.size();
        int hash[10005];
        vector<int> ans;
        
        memset(hash, 255, sizeof(hash));
        for (int i = 0; i < m; i ++) {
            if (hash[queries[i]] == -1) {
                hash[queries[i]] = 0;
                for (int j = 0; j < n; j ++) {
                    if (A[j] < queries[i]) hash[queries[i]] ++;
                }
            }
            
            ans.push_back(hash[queries[i]]);
        }
        
        return ans;
    }
    
    vector<int> sortAndSearch(vector<int> &A, vector<int> &queries) {
        int n = A.size();
        int m = queries.size();
        int hash[10005], sum[10005];
        vector<int> ans, real;
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < n; i ++) {
            if (hash[A[i]] == 0) {
                ans.push_back(A[i]);
            }
            
            hash[A[i]] ++;
        }
        
        sort(ans.begin(), ans.end());
        n = ans.size();
        for (int i = 0; i < n; i ++) {
            if (i) sum[i] = sum[i - 1] + hash[ans[i]]; else sum[i] = hash[ans[i]];
        }
        
        for (int i = 0; i < m; i ++) {
            int rank = lower_bound(ans.begin(), ans.end(), queries[i]) - ans.begin() - 1;
            // printf("rank = %d\n", rank);
            // if (rank < n - 1 || ans[rank] >= queries[i]) rank --;
            real.push_back(rank >= 0 ? sum[rank] : 0);
        }
        
        return real;
    }
    
    int bit[10005];
    
    int lsone(int x) {
        return x & -x;
    }
    
    void update(int x, int MAX) {
        int i = 1;
        for (int i = x; i <= MAX; i += lsone(i)) {
            bit[i] ++;
        }
    }
    
    int sum(int x) {
        int ans = 0;
        
        for (int i = x; i >= 1; i -= lsone(i)) {
            ans += bit[i];
        }
        
        return ans;
    }
    
    vector<int> binaryIndexedTree(vector<int> &A, vector<int> &queries) {
        int n = A.size();
        int m = queries.size();
        vector<int> ans;
        
        for (int i = 0; i < n; i ++) {
            update(A[i] + 1, 10005);
        }
        
        for (int i = 0; i < m; i ++) {
            ans.push_back(sum(queries[i]));
        }
        
        return ans;
    }
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // return justLoop(A, queries);
        // return sortAndSearch(A, queries);
        return binaryIndexedTree(A, queries);
    }
};
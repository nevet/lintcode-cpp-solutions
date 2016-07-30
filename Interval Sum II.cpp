class Solution {
public:
    /* you may need to use some attributes here */
    
    vector<long long> bit;
    vector<int> ori;
    
    int lsone(int x) {
        return x & -x;
    }
    
    void update(int ind, int v) {
        for (int i = ind; i <= bit.size(); i += lsone(i)) {
            bit[i] += (long long)(v);
        }
    }
    
    long long sum(int ind) {
        long long ans = 0;
        for (int i = ind; i > 0; i -= lsone(i)) {
            ans += bit[i];
        }
        
        return ans;
    }
    
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        ori = A;
        bit.assign(A.size() + 1, 0);
        for (int i = 0; i < ori.size(); i ++) {
            update(i + 1, ori[i]);
        }
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return sum(end + 1) - sum(start);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        update(index + 1, value - ori[index]);
        ori[index] = value;
    }
};

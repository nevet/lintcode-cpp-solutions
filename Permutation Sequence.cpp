class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        char f[n + 1];
        for (int i = 0; i < n; i ++) f[i] = i + '1';
        do {
            k --;
            if (k == 0) break;
        } while (next_permutation(f, f + n));
        
        string s;
        for (int i = 0; i < n; i ++) s += f[i];
        return s;
    }
};
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sort(vector<int> &a, int l, int r) {
        if (l >= r) return;
        int i, j, t;
        i = l; j = r;
        t = a[(i + j) >> 1];
        
        while (i <= j) {
            while (i <= j && a[i] < t) i ++;
            while (i <= j && a[j] > t) j --;
            if (i <= j) {
                if (i != j) a[i] ^= a[j] ^= a[i] ^= a[j];
                i ++; j --;
            }
        }
        
        sort(a, l, j);
        sort(a, i, r);
    }
    
    void sortIntegers2(vector<int>& A) {
        sort(A, 0, A.size() - 1);
    }
};
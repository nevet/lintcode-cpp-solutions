// 4 wa
class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        int n = A.size();
        int l = 0;
        int r = n - 1;
        
        if (n == 0) return -1;
        
        while (l < r - 1) {
            int m = (l + r) >> 1;
            
            if (A[m] == target) return m;
            
            if (A[m] > A[l]) {
                if (A[m] > target && target >= A[l]) {
                    r = m - 1;
                } else l = m;
            } else {
                if(A[m] < target && target <= A[r]) {
                    l = m;
                } else r = m - 1;
            }
        }
        
        if (A[l] == target) return l;
        if (A[r] == target) return r;
        
        return -1;
    }
};

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        int n = A.size();
        int l = 0;
        int r = n - 1;
        
        if (n == 0) return false;
        
        while (l < r - 1) {
            int m = (l + r) >> 1;
            
            if (A[m] == target) return true;
            
            if (A[m] > A[l]) {
                if (A[m] > target && target >= A[l]) {
                    r = m - 1;
                } else l = m;
            } else if (A[m] < A[l]){
                if(A[m] < target && target <= A[r]) {
                    l = m;
                } else r = m - 1;
            } else l ++;
        }
        
        if (A[l] == target || A[r] == target) return true;
        
        return false;
    }
};
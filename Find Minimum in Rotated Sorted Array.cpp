// 2 wa
class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &A) {
        int n = A.size();
        
        int l = 0;
        int r = n - 1;
        
        while (l < r - 1) {
            int m = (l + r) >> 1;
            
            if (A[l] < A[m] && A[m] < A[r]) {
                r = m;
            } else
            if (A[l] < A[m] && A[m] > A[r]) {
                l = m;
            } else
            if (A[l] > A[m] && A[m] < A[r]) {
                r = m;
            }
        }
        
        if (A[l] < A[r]) return A[l];
        
        return A[r];
    }
};

// 0 1 2 3 4 5 6 7
// 1 2 3 4 5 6 7 0
// 2 3 4 5 6 7 0 1
// 3 4 5 6 7 0 1 2
// 4 5 6 7 0 1 2 3
// 5 6 7 0 1 2 3 4
// 6 7 0 1 2 3 4 5
// 7 0 1 2 3 4 5 6

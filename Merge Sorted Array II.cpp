// ohko
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int lena = A.size();
        int lenb = B.size();
        
        vector<int> ans(lena + lenb);
        
        int i, j, k;
        
        i = j = k = 0;
        
        while (i < lena && j < lenb) {
            if (A[i] < B[j]) {
                ans[k] = A[i];
                
                i ++;
            } else {
                ans[k] = B[j];
                
                j ++;
            }
            
            k ++;
        }
        
        while (i < lena) {
            ans[k] = A[i];
            k ++;
            i ++;
        }
        
        while (j < lenb) {
            ans[k] = B[j];
            k ++;
            j ++;
        }
        
        return ans;
    }
};

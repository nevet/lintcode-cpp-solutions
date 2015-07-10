// ohko
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int i, j;
        
        i = j = 0;
        
        int len = A.size();
        
        while (i < len) {
            if (A[i] != elem) {
                A[j] = A[i];
                i ++;
                j ++;
                continue;
            }
            
            while (A[i] == elem) i ++;
        }
        
        return j;
    }
};

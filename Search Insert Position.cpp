// ohko
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        return lower_bound(A.begin(), A.end(), target) - A.begin();
    }
};

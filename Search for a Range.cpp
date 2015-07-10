// 2 wa
class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> ans;
        
        ans.push_back(-1);
        ans.push_back(-1);
        
        if (A.empty()) return ans;
        
        int lower = lower_bound(A.begin(), A.end(), target) - A.begin();
        int upper = upper_bound(A.begin(), A.end(), target) - A.begin() - 1;
        
        if (A[lower] != target) return ans;
        
        ans[0] = lower;
        ans[1] = upper;
        
        return ans;
    }
};

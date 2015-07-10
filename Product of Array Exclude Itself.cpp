// 2 wa
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        int n = nums.size(); 
        
        vector<long long> ans(n);
        vector<long long> left(n);
        vector<long long> right(n + 1);
        
        left[0] = nums[0];
        
        for (int i = 1; i < n; i ++) {
            left[i] = left[i - 1] * nums[i];
        }
        
        right[n - 1] = nums[n - 1];
        right[n] = 1;
        
        for (int i = n - 1; i >= 0; i --) {
            right[i] = right[i + 1] * nums[i];
        }
        
        for (int i = 0; i < n; i ++) {
            if (i == 0) {
                ans[i] = right[1];
            } else {
                ans[i] = left[i - 1] * right[i + 1];
            }
        }
        
        return ans;
    }
};

# define MAX 10000

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    int bit[MAX + 5];
    int lsone(int x) {
        return x & -x;
    }
    
    void update(int x) {
        for (int i = x; i <= MAX + 5; i += lsone(i)) {
            bit[i] ++;
        }
    }
    
    int sum(int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lsone(i)) {
            ans += bit[i];
        }
        
        return ans;
    }
    
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> ans;
        int n = A.size();
        
        memset(bit, 0, sizeof(bit));
        
        for (int i = 0; i < n; i ++) {
            update(A[i] + 1);
            ans.push_back(sum(A[i]));
        }
        
        return ans;
    }
};
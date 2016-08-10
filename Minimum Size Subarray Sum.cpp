class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int n = nums.size();
        int t = 0, i = 0, j = 0, ans = n + 1;
        while (j < n) {
            while (j < n && t < s) t += nums[j++];
            
            // fprintf(stderr, "%d %d|", t, j);
            if (t >= s) ans = min(ans, j - i);
            while (i < j && t >= s) {
                t -= nums[i++];
                if (t >= s) ans = min(ans, j - i);
            }
            // fprintf(stderr, "%d %d|", t, i);
            
            if (ans == 1) return 1;
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};
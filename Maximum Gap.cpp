typedef pair<int, int> ii;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int MAX = 2147483647;
    
    int maximumGap(vector<int> nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int mx = nums[0], mn = nums[0];
        
        for (int i = 1; i < n; i ++) {
            mx = max(nums[i], mx);
            mn = min(nums[i], mn);
        }
        
        if (mx == mn) return 0;
        
        int d = (int)ceil((mx - mn) / (1.0 * (n - 1)));
        fprintf(stderr, "%d|", d);
        ii buckets[(mx - mn) / d + 1]; bool vis[(mx - mn) / d + 1];
        for (int i = 0; i <= (mx - mn) / d; i ++) buckets[i] = ii(-MAX, MAX);
        memset(vis, 0, sizeof(vis));
        
        for (int i = 0; i < n; i ++) {
            int ind = (nums[i] - mn) / d;
            vis[ind] = true;
            buckets[ind].first = max(buckets[ind].first, nums[i]);
            buckets[ind].second = min(buckets[ind].second, nums[i]);
        }
        
        int ans = 0;
        int i = 0;
        while (i < (mx - mn) / d) {
            int j = i + 1;
            while (j <= (mx - mn) / d && !vis[j]) j ++;
            ans = max(ans, buckets[j].second - buckets[i].first);
            i = j;
        }
        
        return ans;
    }
};
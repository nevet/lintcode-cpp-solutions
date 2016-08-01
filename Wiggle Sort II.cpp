class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */
    void sortKth(vector<int>& nums, int l, int r, int k) {
        // fprintf(stderr, "%d %d %d|", l, r, k);
        int pivot = nums[(l + r) >> 1];
        int i = l - 1; int j = r + 1;
        for (int k = l; k < j; k ++) {
            if (nums[k] < pivot) {
                i ++;
                if (i != k) nums[i] ^= nums[k] ^= nums[i] ^= nums[k];
            } else if (nums[k] > pivot) {
                j --;
                if (j != k) nums[j] ^= nums[k] ^= nums[j] ^= nums[k];
                k --;
            }
        }
        
        if (i - l + 1 >= k) sortKth(nums, l, i, k); else
        if (j - l >= k) return; else
        sortKth(nums, j, r, k - (j - l));
    }
    
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        int m = (n + 1) / 2;
        sortKth(nums, 0, n - 1, m);
        // for (int i = 0; i < n; i ++) fprintf(stderr, "%d ", nums[i]);
        vector<int> a(n);
        m --;
        
        for (int cur = m; cur >= 0; cur --) a[(m - cur) * 2] = nums[cur];
        for (int cur = n - 1; cur > m; cur --) a[(n - cur) * 2 - 1] = nums[cur];
        // for (int i = 0; i < n; i ++) fprintf(stderr, "%d ", a[i]);
        for (int i = 0; i < n; i ++) nums[i] = a[i];
    }
};
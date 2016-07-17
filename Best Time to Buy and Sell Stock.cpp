class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int f[n], g[n];
        f[0] = prices[0]; g[n - 1] = prices[n - 1];
        for (int i = 1; i < n; i ++) f[i] = min(prices[i], f[i - 1]);
        for (int i = n - 2; i >= 0; i --) g[i] = max(prices[i], g[i + 1]);

        int ans = 0;
        for (int i = 1; i < n; i ++) {
            ans = max(ans, g[i] - f[i - 1]);
        }

        return ans;
    }

    // Solution 2, O(n) time O(1) space
    int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;

        int ans = 0;
        int i = 1;
        int curMin, curMax;
        while (i < n && prices[i] < prices[i - 1]) i ++;
        if (i < n) {
            curMin = prices[i - 1]; curMax = prices[i];
            ans = curMax - curMin;
            i ++;
        }

        while (i < n) {
            if (prices[i] - curMin > ans) {
                ans = prices[i] - curMin;
                curMax = prices[i];
            }

            if (prices[i] < curMin) curMin = prices[i];

            i ++;
        }

        return ans;
    }
};

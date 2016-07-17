class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    void calculateForward(vector<int> &prices, int f[]) {
        int n = prices.size();
        int ans = 0;
        int i = 1;
        int curMin, curMax;
        f[0] = 0;
        while (i < n && prices[i] < prices[i - 1]) {
            f[i++] = 0;
        }
        
        if (i < n) {
            curMin = prices[i - 1]; curMax = prices[i];
            f[i++] = curMax - curMin;
        }
        
        while (i < n) {
            f[i] = f[i - 1];
            if (prices[i] - curMin > f[i]) {
                f[i] = prices[i] - curMin;
                curMax = prices[i];
            }
            
            if (prices[i] < curMin) curMin = prices[i];
            
            i ++;
        }
    }
    
    void calculateBackward(vector<int> &prices, int f[]) {
        int n = prices.size();
        int ans = 0;
        int i = n - 2;
        int curMin, curMax;
        f[n - 1] = 0;
        while (i >= 0 && prices[i] > prices[i + 1]) {
            f[i--] = 0;
        }
        
        if (i >= 0) {
            curMin = prices[i]; curMax = prices[i + 1];
            f[i--] = curMax - curMin;
        }
        
        while (i >= 0) {
            f[i] = f[i + 1];
            if (curMax - prices[i] > f[i]) {
                f[i] = curMax - prices[i];
                curMin = prices[i];
            }
            
            if (prices[i] > curMax) curMax = prices[i];
            
            i --;
        }
    }
    
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int f[n], g[n];
        calculateForward(prices, f);
        calculateBackward(prices, g);
        
        // for (int i = 0; i < n; i ++) fprintf(stderr, "%d ", f[i]);
        // fprintf(stderr, "|");
        // for (int i = 0; i < n; i ++) fprintf(stderr, "%d ", g[i]);
        
        int ans = f[n - 1];
        for (int i = 1; i < n - 1; i ++) {
            ans = max(ans, f[i - 1] + g[i]);
        }
        
        return ans;
    }
};
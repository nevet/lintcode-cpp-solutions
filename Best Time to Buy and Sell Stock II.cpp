class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // assume [a,..., a + k, b, ..., b + p]
        // if sell separately, S1 = k + p
        // if keep until b + p, S2 = b + p - a
        // if S1 > S2, we have k + p > b + p - a, i.e. a + k > b
        // so once price goes down, we have to sell in order to get max profit
        int curMin, curMax, ans;
        if (prices.size() == 0) return 0;
        
        curMin = curMax = prices[0];
        ans = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] > curMax) curMax = prices[i]; else
            if (prices[i] < prices[i - 1]) {
                ans += curMax - curMin;
                curMin = curMax = prices[i];
            }
        }
        
        return ans + curMax - curMin;
    }
};
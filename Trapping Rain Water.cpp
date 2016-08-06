class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) return 0;
        
        int i, j, ans;
        i = ans = 0; j = n - 1;
        while (i < j) {
            if (heights[i] <= heights[j]) {
                int k = i + 1;
                while (heights[k] <= heights[i] && k < j) ans += heights[i] - heights[k++];
                i = k;
            } else {
                int k = j - 1;
                while (heights[k] <= heights[j] && k > i) ans += heights[j] - heights[k--];
                j = k;
            }
        }
        
        return ans;
    }
};
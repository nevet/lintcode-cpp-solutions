class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    typedef pair<int, int> ii;
    int largestRectangleArea(vector<int> &height) {
        stack<ii> stk;
        int n = height.size();
        int ans = 0;
        
        for (int i = 0; i < n; i ++) {
            int lowest = i;
            while (!stk.empty() && stk.top().first > height[i]) {
                lowest = stk.top().second;
                ans = max(ans, stk.top().first * (i - lowest));
                stk.pop();
            }
            stk.push(ii(height[i], lowest));
        }
        
        while (!stk.empty()) {
            ans = max(ans, stk.top().first * (n - stk.top().second));
            stk.pop();
        }
        
        return ans;
    }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            if (dq.empty()) {
                dq.push_back(i);
            } else {
                while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
                dq.push_back(i);
                if (i - dq.front() >= k) dq.pop_front();
            }
            
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        
        return ans;
    }
};

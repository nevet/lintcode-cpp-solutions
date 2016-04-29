class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        priority_queue<int> left_max;
        priority_queue<int, vector<int>, greater<int>> right_min;
        vector<int> ans;
        
        int n = nums.size();
        if (n == 0) return ans;
        if (n > 0) {
            left_max.push(nums[0]);
            ans.push_back(nums[0]);
        }

        for (int i = 1; i < n; i ++) {
            if (right_min.empty() || !right_min.empty() && nums[i] < right_min.top()) {
                left_max.push(nums[i]);
            } else {
                right_min.push(nums[i]);
            }
            
            if (right_min.size() > left_max.size()) {
                left_max.push(right_min.top());
                right_min.pop();
            } else if (left_max.size() - right_min.size() > 1) {
                right_min.push(left_max.top());
                left_max.pop();
            }
            
            ans.push_back(left_max.top());
        }
        
        return ans;
    }
};

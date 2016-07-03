class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    
    int abs(int x) {
        return x < 0 ? -x : x;
    }
    
    vector<int> subarraySumClosest(vector<int> nums){
        vii sum;
        vector<int> ans;
        
        if (nums.size() == 0) return ans;
        
        int m = 2147483647;
        int mi, mj;
        
        mi = mj = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i) sum.push_back(ii(sum[i - 1].first + nums[i], i)); else
            sum.push_back(ii(nums[i], i));
            
            if (abs(nums[i]) < m) {
                m = abs(nums[i]);
                mi = mj = i;
            }
        }
        
        sort(sum.begin(), sum.end());
        
        for (int i = 1; i < sum.size(); i ++) {
            if (sum[i].first - sum[i - 1].first < m) {
                m = sum[i].first - sum[i - 1].first;
                mi = min(sum[i].second, sum[i - 1].second) + 1;
                mj = max(sum[i].second, sum[i - 1].second);
            }
        }
        
        ans.push_back(mi); ans.push_back(mj);
        
        return ans;
    }
};

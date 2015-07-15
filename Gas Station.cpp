// 2 wa
class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int sum = 0;
        int cur = 0;
        int ans = 0;
        
        for (int i = 0; i < n; i ++) {
            if (i == 0) {
                sum = cur = gas[i] - cost[i];
            } else {
                sum += gas[i] - cost[i];
                
                if (gas[i] - cost[i] > cur) {
                    cur = gas[i] - cost[i];
                    ans = i;
                } else {
                    cur += gas[i] - cost[i];
                }
            }
        }
        
        if (sum >= 0) return ans;
        
        return -1;
    }
};

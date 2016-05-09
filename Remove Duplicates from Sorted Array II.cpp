class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        int i, j, cur;
        i = j = cur = 0;
        while (i < n) {
            if (nums[i] == nums[i + 1]) {
                nums[cur] = nums[cur + 1] = nums[i];
                cur += 2;
                
                j = i + 2;
                while (j < n && nums[j] == nums[i]) j ++;
                i = j;
            } else {
                nums[cur] = nums[i];
                cur ++; i ++;
            }
        }
        
        return cur;
    }
};
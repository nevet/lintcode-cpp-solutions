// 1 wa
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        int i, j;
        
        i = j = 0;
        
        int len = nums.size();
        
        while (j < len) {
            nums[i] = nums[j];
            
            while (j < len && nums[j] == nums[i]) j ++;
            
            i ++;
        }
        
        return i;
    }
};

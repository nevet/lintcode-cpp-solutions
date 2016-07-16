class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int n = num.size();
        if (n == 0) return 0;
        if (n == 1) return num[0];
        
        int i = 0; int j = num.size() - 1;
        
        while (i < j) {
            int m = (i + j) >> 1;
            
            if (num[m] < num[j]) j = m; else
            if (num[m] > num[j]) i = m + 1; else j --;
        }
        
        return num[i];
    }
};
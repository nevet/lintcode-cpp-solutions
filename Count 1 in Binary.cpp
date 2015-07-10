// ohko
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int ans = 0;
        
        while (num) {
            num &= num - 1;
            ans ++;
        }
        
        return ans;
    }
};

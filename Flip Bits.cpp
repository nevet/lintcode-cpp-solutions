// ohko
class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int t = a ^ b;
        int ans = 0;
        
        while (t) {
            t &= t - 1;
            ans ++;
        }
        
        return ans;
    }
};

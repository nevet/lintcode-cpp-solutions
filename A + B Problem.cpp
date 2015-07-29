// 6 wa
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        int ans = 0;
        int carry = 0;
        
        for (int i = 0; i < 32; i ++) {
            int mask = 1 << i;
            int cur = (a & mask) ^ (b & mask);
            
            carry <<= 1;
            
            ans |= cur ^ carry;
            
            if ((a & mask) | (b & mask)) {
                if (!carry && !cur) {
                    carry = mask;
                }
            } else {
                carry = 0;
            }
        }
        
        return ans;
    }
};
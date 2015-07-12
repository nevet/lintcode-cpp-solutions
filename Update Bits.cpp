// > 10 wa
class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mask_front = j == 31 ? 0 : (-1) << (j + 1);
        int mask_tail = (1 << i) - 1;
        
        return n & (mask_tail | mask_front) | (m << i);
    }
};
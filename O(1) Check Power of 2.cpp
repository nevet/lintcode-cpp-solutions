// 2 wa
class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        if (n <= 0) return false;
        
        return (n & (n - 1)) == 0;
    }
};

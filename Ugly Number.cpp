class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        if (num == 0) return false;
        
        while (num % 2 == 0) {
            num /= 2;
        }
        
        while (num % 5 == 0) {
            num /= 5;
        }
        
        while (num % 3 == 0) {
            num /= 3;
        }
        
        return num == 1;
    }
};
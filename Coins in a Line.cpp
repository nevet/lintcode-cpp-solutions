class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // 1 - true
        // 2 - true
        // 3 - false
        // 4 - true
        // 5 - true
        // 6 - false
        if (n == 0) return false;
        
        int res[3] = {true, true, false};
        return res[(n - 1) % 3];
    }
};
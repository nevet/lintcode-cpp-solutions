class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int n = digits.size() - 1;
        digits[n] ++;
        
        while (n) {
            if (digits[n] >= 10) {
                digits[n - 1] += digits[n] / 10;
                digits[n] %= 10;
                n --;
            } else break;
        }
        
        if (digits[0] >= 10) {
            result.push_back(1);
            digits[0] %= 10;
        }
        
        for (int i = 0; i < digits.size(); i ++) {
            result.push_back(digits[i]);
        }
        
        return result;
    }
};
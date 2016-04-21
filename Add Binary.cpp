class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        string la = a.length() > b.length() ? a : b;
        string lb = la == a ? b : a;
        int len = la.length();
        while (lb.length() < len) {
            lb = "0" + lb;
        }
        
        string c = "";
        int carry = 0;
        
        for (int i = len - 1; i >= 0; i --) {
            c = (char)((la[i] + lb[i] - 96 + carry) % 2 + 48) + c;
            carry = (carry + la[i] + lb[i] - 96) / 2;
        }
        
        return carry ? "1" + c : c;
    }
};
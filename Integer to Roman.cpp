class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        int p[7] = {1, 5, 10, 50, 100, 500, 1000};
        int mapper[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        
        string s = "";
        int cur = 6;
        while (n) {
            while (n < p[cur]) cur -= 2;
            fprintf(stderr, "%d %d|", n, cur);
            int x = n / p[cur];
            if (x == 4) { s += mapper[cur]; s += mapper[cur + 1]; n %= p[cur]; } else
            if (x == 9) { s += mapper[cur]; s += mapper[cur + 2]; n %= p[cur]; } else
            if (x >= 5) { s += mapper[cur + 1]; n -= p[cur + 1]; } else {
                while (x--) s += mapper[cur]; n %= p[cur];
            }
        }
        
        return s;
    }
};
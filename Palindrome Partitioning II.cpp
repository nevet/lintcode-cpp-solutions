class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    bool ok(string s) {
        int i, j;
        i = 0; j = s.length() - 1;
        while (i <= j && s[i] == s[j]) {
            i ++; j --;
        }

        return i > j;
    }

    int minCutTLE(string s) {
        if (ok(s)) return 0;

        int len = s.length();
        int curBest = 10000000;
        for (int i = 1; i <= len; i ++) {
            string sub = s.substr(0, i);
            if (ok(sub)) {
                curBest = min(curBest, 1 + minCut(s.substr(i, len - i)));
            }
        }

        return curBest;
    }

    int minCut(string s) {
        // f[i] = min(f[j] + 1, s[j + 1, i] is a palindrome)
        // do directly takes O(n^3) since finding and verifying palindrome is really
        // tedious, we could make use of previous calculation results to save the
        // lookup time.
        // palin[i] contains all possible positions, such that s[palin[i], i] is a
        // palindrome. Then palin[i + 1] could be constructed out of palin[i], by
        // selecting palin[i] where s[palin[i] - 1] == s[i + 1] holds. Notice that
        // we need to put i and i + 1 into palin[i], since s[i] could form a palindrome
        // by itself (i), and form a palindrome with previous letter (i + 1, since
        // we need to check this in the next iteration).
        int len = s.length();
        int f[len + 5];
        vector<int> palin[2];
        for (int i = 1; i < len; i ++) {
            f[i] = i ? f[i - 1] + 1 : 0;
            palin[i & 1].clear();
            palin[i & 1].push_back(i + 1); // to take s[i - 1, i] into account
            palin[i & 1].push_back(i);
            // check if it could form palindrome with palindromes ended at previous letter
            for (int j = 0; j < palin[(i & 1) ^ 1].size(); j ++) {
                int pos = palin[(i & 1) ^ 1][j];
                if (pos > 0 && s[pos - 1] == s[i]) {
                    palin[i & 1].push_back(pos - 1);
                    f[i] = min(f[i], pos == 1 ? 0 : f[pos - 2] + 1);
                }
            }
        }

        return f[len - 1];
    }
};

//fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi

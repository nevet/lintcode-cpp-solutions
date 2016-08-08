class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // f[i] = a[i] + a[i + 1] * (f[i + 2] < f[i + 1]) + f[second_hand_decision]
        int n = values.size();
        if (n <= 2) return true;
        int f[n + 1], g[n];
        f[n] = 0; f[n - 1] = values[n - 1]; f[n - 2] = values[n - 2] + values[n - 1];
        g[n - 1] = g[n - 2] = n; 
        for (int i = n - 3; i >= 0; i --) {
            if (f[i + 1] < f[i + 2]) {
                f[i] = values[i] + f[g[i + 1]];
                g[i] = i + 1;
            } else {
                f[i] = values[i] + values[i + 1] + f[g[i + 2]];
                g[i] = i + 2;
            }
        }
        
        return f[0] > f[g[0]];
    }
};

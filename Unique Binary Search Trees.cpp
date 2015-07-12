// ohko, need to recite
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // Table to store results of subproblems
        int catalan[n+1];
     
        // Initialize first two values in table
        catalan[0] = catalan[1] = 1;
     
        // Fill entries in catalan[] using recursive formula
        for (int i=2; i<=n; i++)
        {
            catalan[i] = 0;
            for (int j=0; j<i; j++)
                catalan[i] += catalan[j] * catalan[i-j-1];
        }
     
        // Return last entry
        return catalan[n];
    }
};

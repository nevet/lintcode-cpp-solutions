class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        
        int i, j, ans;
        i = ans = 0;
        j = 1;
        int curInc = -1;
        while (i < n) {
            int cur = 1;
            
            if (j == n) {
                ans ++;
                break;
            } else if (ratings[j] > ratings[i]) {
                while (j < n && ratings[j] > ratings[i]) {
                    i ++; j ++; cur ++;
                }
                fprintf(stderr, "increasing: %d\n", cur);
                ans += cur * (cur + 1) / 2;
                curInc = cur;
                if (j == n) break;
                if (ratings[j] == ratings[i]) { curInc = -1; i ++; j = i + 1;}
            } else if (ratings[j] < ratings[i]) {
                while (j < n && ratings[j] < ratings[i]) {
                    i ++; j ++; cur ++;
                }
                fprintf(stderr, "decreasing: %d\n", cur);
                if (curInc != -1 && cur >= curInc) {
                    ans -= curInc;
                } else if (curInc != -1 && cur < curInc) {
                    cur --;
                }
                ans += cur * (cur + 1) / 2;
                if (j == n) break;
                if (ratings[j] == ratings[i]) { i ++; j = i + 1; } else
                if (ratings[j] > ratings[i]) ans --;
                curInc = -1;
            } else {
                while (j < n && ratings[i] == ratings[j]) {
                    i ++; j ++; cur ++;
                }
                fprintf(stderr, "equal: %d\n", cur);
                if (j < n) cur --;
                ans += cur;
                if (j == n) break;
                curInc = -1;
            }
            
            fprintf(stderr, "cur ans: %d \n", ans);
        }
        
        return ans;
    }
};
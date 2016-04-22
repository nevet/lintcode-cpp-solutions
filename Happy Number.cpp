class Solution {
public:
    int decompose(int n) {
        int x = 0;
        while (n) {
            x += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return x;
    }
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        set<int> hash;
        
        while (hash.empty() || hash.find(n) == hash.end()) {
            if (n == 1) {
                return true;
            }
            
            hash.insert(n);
            n = decompose(n);
            // printf("%d\n", n);
        }
        
        return false;
    }
};
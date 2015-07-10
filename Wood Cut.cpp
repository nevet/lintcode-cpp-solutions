// 4 wa
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    bool cut(vector<int> v, int x, int k) {
        int t = 0;
        int n = v.size();
        
        if (x == 0) return true;
        
        for (int i = 0; i < n; i ++) {
            t += v[i] / x;
        }
        
        return t >= k;
    }
    
    int woodCut(vector<int> L, int k) {
        long long l, r;
        int n = L.size();
        
        l = r = 0;
        
        for (int i = 0; i < n; i ++) {
            r = max(r, (long long)L[i]);
        }
        
        while (l < r - 1) {
            int m = ((l + r) >> 1LL);
            
            if (!cut(L, m, k)) r = m - 1; else l = m;
        }
        
        if (cut(L, r, k)) return r;
        
        return l;
    }
};

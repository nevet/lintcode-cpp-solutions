// 4 wa
/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int l = 1;
        int r = n;
        int t;
        
        while (l < r - 1) {
            t = (l + r) >> 1;
            if (VersionControl::isBadVersion(t)) r = t; else l = t + 1;
        }
        
        if (VersionControl::isBadVersion(l)) return l;
        
        return r;
    }
};

// 1 2 3 4 5
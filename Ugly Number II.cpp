# define MAXINT 2147483647

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        priority_queue<int> pq;
        pq.push(-1);
        set<int> hash;
        hash.insert(-1);
        for (int i = 2; i <= n; i ++) {
            int u = pq.top(); pq.pop();
            if (-u > MAXINT + u) continue;
            if (hash.find(u * 2) == hash.end()) { pq.push(u * 2); hash.insert(u * 2); }
            if (-u * 2 > MAXINT + u) continue;
            if (hash.find(u * 3) == hash.end()) { pq.push(u * 3); hash.insert(u * 3); }
            if (-u * 3 > MAXINT + u * 2) continue;
            if (hash.find(u * 5) == hash.end()) { pq.push(u * 5); hash.insert(u * 5); }
        }
        return -pq.top();
    }
};

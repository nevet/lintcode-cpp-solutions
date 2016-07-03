/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
     
    int lsone(int x) {
        return x & -x;
    }
     
    void update(vector<long long> &bit, int x, int v) {
        for (int i = x; i < bit.size(); i += lsone(i)) {
            bit[i] += v;
        }
    }

    long long sum(vector<long long> &bit, int x) {
        long long ans = 0;
        for (int i = x; i >= 1; i -= lsone(i)) {
            ans += bit[i];
        }
        
        return ans;
    }
    
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> bit(A.size() + 10);
        vector<long long> ans;
        
        for (int i = 0; i < A.size(); i ++) {
            update(bit, i + 1, A[i]);
        }
        
        for (int i = 0; i < queries.size(); i ++) {
            if (queries[i].start == 0) ans.push_back(sum(bit, queries[i].end + 1)); else {
                ans.push_back(sum(bit, queries[i].end + 1) - sum(bit, queries[i].start));
            }
        }
        
        return ans;
    }
};
bool cmp(int a, int b) {
    return a > b;
}

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        make_heap(A.begin(), A.end(), cmp);
    }
};
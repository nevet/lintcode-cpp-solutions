class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    // 2-pass
    void rerange(vector<int> &A) {
        if (A.size() == 0) return;
        
        int head, tail;
        head = 0; tail = A.size() - 1;
        
        while (head < tail) {
            while (head < tail && A[head] < 0) head ++;
            while (head < tail && A[tail] > 0) tail --;
            
            if (head < tail) {
                A[head] ^= A[tail] ^= A[head] ^= A[tail];
                head ++; tail --;
            }
        }
        
        int delta = 1;
        if (head * 2 < A.size()) {
            tail = head - 1;
            head = A.size() - 2;
            delta = -1;
        } else {
            tail = head;
            head = 1;
        }
        
        while (head != tail) {
            A[head] ^= A[tail] ^= A[head] ^= A[tail];
            head += 2 * delta;
            tail += delta;
        }
    }
};

//[-33,-19,30,26,21,-9]
//[-13,-8,-12,-15,-14,35,7,-1,11,27,10,-7,-12,28,18]
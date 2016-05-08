class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        int remainOne, remainTwo;
        remainOne = remainTwo = 0;
        int n = A.size();
        remainOne = A[0];
        for (int i = 1; i < n; i ++) {
            int t = A[i] & remainTwo; A[i] ^= t; remainTwo ^= t; 
            int s = A[i] & remainOne; A[i] ^= s; remainOne = remainOne ^ s | A[i];
            remainTwo |= s;
        }
        
        return remainOne;
    }
};
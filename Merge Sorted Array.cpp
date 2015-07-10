// ohko
class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int a[], int n, int b[], int m) {
        int p = n + m - 1;
    	int curA = n - 1;
    	int curB = m - 1;
    
    	while (p >= 0)
    	{
    		if (a[curA] > b[curB])
    		{
    			a[p] = a[curA];
    			curA --;
    		} else
    		{
    			a[p] = b[curB];
    			curB --;
    		}
    
    		p --;
    	}
    }
};

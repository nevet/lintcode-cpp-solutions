// ohko
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        int t = lower_bound(array.begin(), array.end(), target) - array.begin();
        
        if (array[t] == target) return t;
        
        return -1;
    }
};

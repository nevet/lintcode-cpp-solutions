public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    public int median(int[] nums) {
        return sub(nums, 0, nums.length - 1, (nums.length + 1)/2);
    }
    private int sub(int[] nums, int start, int end, int size) {
        int mid = (start + end) / 2;
        int pivot = nums[mid];
        int i = start - 1, j = end + 1;
        for (int k = start; k < j; k++) {
            if (nums[k] < pivot) {
                i++;
                int tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
            } else if (nums[k] > pivot) {
                j--;
                int tmp = nums[j];
                nums[j] = nums[k];
                nums[k] = tmp;
                k--;
            }
        }
        if (i - start + 1 >= size) {
            return sub(nums, start, i, size);
        } else if (j - start >= size) {
            return nums[j-1];
        } else {
            return sub(nums, j, end, size - (j - start));
        }
    }
}
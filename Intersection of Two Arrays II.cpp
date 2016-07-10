class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mapper;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i ++) mapper[nums1[i]] ++;
        for (int i = 0; i < nums2.size(); i ++) {
            if (mapper.count(nums2[i]) > 0 && mapper[nums2[i]] != 0) {
                ans.push_back(nums2[i]);
                mapper[nums2[i]] --;
            }
        }
        
        return ans;
    }
};
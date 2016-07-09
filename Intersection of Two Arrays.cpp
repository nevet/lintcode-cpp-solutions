class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i ++) s.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i ++) {
            auto it = s.find(nums2[i]);
            if (it != s.end()) {
                s.erase(it);
                ans.push_back(nums2[i]);
            }
        }
        
        return ans;
    }
};
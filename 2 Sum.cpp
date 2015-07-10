// 4 wa
typedef pair<int, int> ii;

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        vector<ii> a;
        
        for (int i = 0; i < nums.size(); i ++) {
            a.push_back(ii(nums[i], i));
        }
        
        sort(a.begin(), a.end());
        
        int i, j;
        
        i = 0;
        j = nums.size() - 1;
        
        while (i < j) {
            if (a[i].first + a[j].first < target) i ++; else
            if (a[i].first + a[j].first > target) j --; else {
                ans.push_back(a[i].second + 1);
                ans.push_back(a[j].second + 1);
                
                if (ans[0] > ans[1]) ans[0] ^= ans[1] ^= ans[0] ^= ans[1];
                
                return ans;
            }
        }
    }
};

